// Copyright 2016 The Fuchsia Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef GARNET_LIB_MAGMA_SRC_MAGMA_UTIL_PLATFORM_ZIRCON_ZIRCON_PLATFORM_IOCTL_H_
#define GARNET_LIB_MAGMA_SRC_MAGMA_UTIL_PLATFORM_ZIRCON_ZIRCON_PLATFORM_IOCTL_H_

#include "zircon/device/ioctl-wrapper.h"
#include "zircon/device/ioctl.h"

#define IOCTL_MAGMA_DUMP_STATUS IOCTL(IOCTL_KIND_DEFAULT, IOCTL_FAMILY_GPU, 1)
#define IOCTL_MAGMA_TEST_RESTART IOCTL(IOCTL_KIND_DEFAULT, IOCTL_FAMILY_GPU, 2)

#endif // GARNET_LIB_MAGMA_SRC_MAGMA_UTIL_PLATFORM_ZIRCON_ZIRCON_PLATFORM_IOCTL_H_
