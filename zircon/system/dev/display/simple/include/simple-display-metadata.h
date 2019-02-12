// Copyright 2019 The Fuchsia Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#pragma once

#include <ddk/metadata.h>
#include <zircon/pixelformat.h>

// "FB!"
#define SIMPLE_DISPLAY_METADATA (0x46422100 | DEVICE_METADATA_PRIVATE)

typedef struct {
    zx_paddr_t base;
    size_t size;
    uint32_t width;
    uint32_t height;
    uint32_t stride;
    zx_pixel_format_t format;
} simple_display_metadata_t;
