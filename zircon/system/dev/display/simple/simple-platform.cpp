// Copyright 2019 The Fuchsia Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <ddk/binding.h>
#include <ddk/device.h>
#include <ddk/driver.h>
#include <ddk/platform-defs.h>

#include "simple-display-metadata.h"
#include "simple-display.h"

static zx_status_t simple_platform_disp_bind(void* ctx, zx_device_t* dev) {
    zx_status_t status;

    simple_display_metadata_t metadata;
    size_t metadata_actual;

    status = device_get_metadata(dev, SIMPLE_DISPLAY_METADATA, &metadata, sizeof(metadata), &metadata_actual);

    if (status != ZX_OK) {
        zxlogf(ERROR, "failed to get metadata - status: %d", status);
        return status;
    }

    if (metadata_actual < sizeof(simple_display_metadata_t)) {
        zxlogf(ERROR, "metadata is of size %zu, needs to at least be %zu",
               metadata_actual, sizeof(simple_display_metadata_t));
        return ZX_ERR_INTERNAL;
    }

    std::optional<ddk::MmioBuffer> framebuffer_mmio;
    zx::unowned_resource resource(get_root_resource());

    status = ddk::MmioBuffer::Create(metadata.base, metadata.size,
                                     *resource, ZX_CACHE_POLICY_WRITE_COMBINING, &framebuffer_mmio);

    if (status != ZX_OK) {
        zxlogf(ERROR, "failed to map framebuffer - status: %d", status);
        return status;
    }

    fbl::AllocChecker ac;
    fbl::unique_ptr<SimpleDisplay> display(new (&ac) SimpleDisplay(
        dev, std::move(*framebuffer_mmio), metadata.width, metadata.height, metadata.stride, metadata.format));
    if (!ac.check()) {
        return ZX_ERR_NO_MEMORY;
    }

    return display->Bind("simple_platform_disp", &display);
}

static zx_driver_ops_t simple_platform_disp_driver_ops = {
    .version = DRIVER_OPS_VERSION,
    .init = nullptr,
    .bind = simple_platform_disp_bind,
    .create = nullptr,
    .release = nullptr,
};

// clang-format off
ZIRCON_DRIVER_BEGIN(simple_platform_disp, simple_platform_disp_driver_ops, "zircon", "*0.1", 3)
    BI_ABORT_IF(NE, BIND_PLATFORM_DEV_VID, PDEV_VID_GENERIC),
    BI_ABORT_IF(NE, BIND_PLATFORM_DEV_PID, PDEV_PID_GENERIC),
    BI_MATCH_IF(EQ, BIND_PLATFORM_DEV_DID, PDEV_DID_SIMPLE_DISPLAY),
ZIRCON_DRIVER_END(simple_platform_disp)
