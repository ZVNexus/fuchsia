// Copyright 2019 The Fuchsia Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <threads.h>
#include <unistd.h>

#include <ddk/binding.h>
#include <ddk/debug.h>
#include <ddk/device.h>
#include <ddk/driver.h>
#include <ddk/platform-defs.h>

#include <zircon/assert.h>
#include <zircon/process.h>
#include <zircon/syscalls.h>
#include <zircon/threads.h>

#include "sargo.h"

static void sargo_release(void* ctx) {
    sargo_t* sargo = ctx;

    free(sargo);
}

static zx_protocol_device_t sargo_device_protocol = {
    .version = DEVICE_OPS_VERSION,
    .release = sargo_release,
};

static zx_status_t sargo_bind(void* ctx, zx_device_t* parent) {
    sargo_t* sargo = calloc(1, sizeof(sargo_t));
    if (!sargo) {
        return ZX_ERR_NO_MEMORY;
    }

    zx_status_t status = device_get_protocol(parent, ZX_PROTOCOL_PBUS, &sargo->pbus);
    if (status != ZX_OK) {
        free(sargo);
        return ZX_ERR_NOT_SUPPORTED;
    }

    device_add_args_t args = {
        .version = DEVICE_ADD_ARGS_VERSION,
        .name = "sargo",
        .ctx = sargo,
        .ops = &sargo_device_protocol,
        // nothing should bind to this device
        // all interaction will be done via the pbus_interface_t
        .flags = DEVICE_ADD_NON_BINDABLE,
    };

    status = device_add(parent, &args, NULL);
    if (status != ZX_OK) {
        goto fail;
    }

    if ((status = sargo_add_devices(sargo)) != ZX_OK) {
        zxlogf(WARN, "sargo_add_devices failed %d\n", status);
    }

    return ZX_OK;

fail:
    zxlogf(ERROR, "sargo_bind failed %d\n", status);
    sargo_release(sargo);
    return status;
}

static zx_driver_ops_t sargo_driver_ops = {
    .version = DRIVER_OPS_VERSION,
    .bind = sargo_bind,
};

ZIRCON_DRIVER_BEGIN(sargo, sargo_driver_ops, "zircon", "0.1", 3)
    BI_ABORT_IF(NE, BIND_PROTOCOL, ZX_PROTOCOL_PBUS),
    BI_ABORT_IF(NE, BIND_PLATFORM_DEV_VID, PDEV_VID_GOOGLE),
    BI_MATCH_IF(EQ, BIND_PLATFORM_DEV_PID, PDEV_PID_SARGO),
ZIRCON_DRIVER_END(sargo)
