// Copyright 2019 The Fuchsia Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <ddk/debug.h>
#include <ddk/metadata.h>
#include <ddk/platform-defs.h>

#include <stdio.h>

#include <simple-display-metadata.h>

#include "sargo.h"

static const simple_display_metadata_t sargo_display_metadata = {
    .base = 0x9d400000,
    .size = 1440 * 2960 * 4,
    .width = 1440,
    .height = 2960,
    .stride = 1440,
    .format = ZX_PIXEL_FORMAT_RGB_x888,
};

static const pbus_metadata_t sargo_display_metadata_list[] = {
    {
        .type = SIMPLE_DISPLAY_METADATA,
        .data_buffer = &sargo_display_metadata,
        .data_size = sizeof(sargo_display_metadata),
    }};

static const pbus_dev_t sargo_display_dev = {
    .name = "sargo-display",
    .vid = PDEV_VID_GENERIC,
    .pid = PDEV_PID_GENERIC,
    .did = PDEV_DID_SIMPLE_DISPLAY,
    .metadata_list = sargo_display_metadata_list,
    .metadata_count = countof(sargo_display_metadata_list),
};

zx_status_t sargo_add_devices(sargo_t* sargo) {
    zx_status_t status;

    if ((status = pbus_device_add(&sargo->pbus, &sargo_display_dev)) != ZX_OK) {
        zxlogf(ERROR, "sargo_add_devices could not add sargo_display_dev: %d\n", status);
    }

    return ZX_OK;
}
