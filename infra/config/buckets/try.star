# Copyright 2019 The Fuchsia Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

load("//common/specs.star", specs="specs")

load(
    "@proto//recipes/fuchsia.proto",
    fuchsia_pb="recipe_modules.infra.fuchsia",
)

try_specs = [
    specs.spec(
        name="fuchsia-arm64-debug",
        protobuf=fuchsia_pb.Fuchsia(
            checkout=fuchsia_pb.Fuchsia.Checkout(
                manifest="flower",
                project="integration",
                remote="https://fuchsia.googlesource.com/integration",
            ),
            build=fuchsia_pb.Fuchsia.Build(
                build_type="debug",
                board="boards/arm64.gni",
                packages=["//bundles/buildbot:core"],
                product="products/core.gni",
                run_tests=True,
                target="arm64",
                variants=["host_asan"],
            ),
            test=fuchsia_pb.Fuchsia.Test(
                device_type="QEMU",
                pave=True,
                pool="fuchsia.tests",
                test_in_shards=True,
                timeout_secs=1800,
            ),
        )),
    specs.spec(
        name="fuchsia-arm64-debug-build_default",
        protobuf=fuchsia_pb.Fuchsia(
            checkout=fuchsia_pb.Fuchsia.Checkout(
                manifest="flower",
                project="integration",
                remote="https://fuchsia.googlesource.com/integration",
            ),
            build=fuchsia_pb.Fuchsia.Build(
                build_type="debug",
                board="boards/arm64.gni",
                ninja_targets=[":default"],
                packages=["//bundles/buildbot:core"],
                product="products/core.gni",
                target="arm64",
            ),
            test=fuchsia_pb.Fuchsia.Test(
                device_type="QEMU",
                pave=True,
                pool="fuchsia.tests",
                timeout_secs=2400,
            ))),
    specs.spec(
        name="fuchsia-arm64-release",
        protobuf=fuchsia_pb.Fuchsia(
            checkout=fuchsia_pb.Fuchsia.Checkout(
                manifest="flower",
                project="integration",
                remote="https://fuchsia.googlesource.com/integration",
            ),
            build=fuchsia_pb.Fuchsia.Build(
                build_type="release",
                board="boards/arm64.gni",
                packages=["//bundles/buildbot:core"],
                product="products/core.gni",
                run_tests=True,
                target="arm64",
                variants=["host_asan"],
            ),
            test=fuchsia_pb.Fuchsia.Test(
                device_type="QEMU",
                pave=True,
                pool="fuchsia.tests",
                test_in_shards=True,
                timeout_secs=1800,
            ))),
    specs.spec(
        name="fuchsia-host-mac",
        protobuf=fuchsia_pb.Fuchsia(
            checkout=fuchsia_pb.Fuchsia.Checkout(
                manifest="flower",
                project="integration",
                remote="https://fuchsia.googlesource.com/integration",
            ),
            build=fuchsia_pb.Fuchsia.Build(
                build_type="release",
                environment_tags=["mac"],
                exclude_images=True,
                packages=["//bundles/buildbot:core"],
                product="products/core.gni",
                run_tests=True,
                target="x64",
            ),
            test=fuchsia_pb.Fuchsia.Test(
                device_type="QEMU",
                pave=True,
                pool="fuchsia.tests",
                test_in_shards=True,
                timeout_secs=2400,
            ))),
    specs.spec(
        name="fuchsia-x64-debug",
        protobuf=fuchsia_pb.Fuchsia(
            checkout=fuchsia_pb.Fuchsia.Checkout(
                manifest="flower",
                project="integration",
                remote="https://fuchsia.googlesource.com/integration",
            ),
            build=fuchsia_pb.Fuchsia.Build(
                build_type="debug",
                board="boards/x64.gni",
                packages=["//bundles/buildbot:core"],
                product="products/core.gni",
                run_tests=True,
                target="x64",
                variants=["host_asan"],
            ),
            test=fuchsia_pb.Fuchsia.Test(
                device_type="QEMU",
                pave=True,
                pool="fuchsia.tests",
                test_in_shards=True,
                timeout_secs=1800,
            ))),
    specs.spec(
        name="fuchsia-x64-debug-build_default",
        protobuf=fuchsia_pb.Fuchsia(
            checkout=fuchsia_pb.Fuchsia.Checkout(
                manifest="flower",
                project="integration",
                remote="https://fuchsia.googlesource.com/integration",
            ),
            build=fuchsia_pb.Fuchsia.Build(
                build_type="debug",
                board="boards/x64.gni",
                ninja_targets=[":default"],
                packages=["//bundles/buildbot:core"],
                product="products/core.gni",
                target="x64",
            ),
            test=fuchsia_pb.Fuchsia.Test(
                device_type="QEMU",
                pave=True,
                pool="fuchsia.tests",
                timeout_secs=2400,
            ))),
    specs.spec(
        name="fuchsia-x64-release",
        protobuf=fuchsia_pb.Fuchsia(
            checkout=fuchsia_pb.Fuchsia.Checkout(
                manifest="flower",
                project="integration",
                remote="https://fuchsia.googlesource.com/integration",
            ),
            build=fuchsia_pb.Fuchsia.Build(
                build_type="release",
                board="boards/x64.gni",
                packages=["//bundles/buildbot:core"],
                product="products/core.gni",
                run_tests=True,
                target="x64",
                variants=["host_asan"],
            ),
            test=fuchsia_pb.Fuchsia.Test(
                device_type="QEMU",
                pave=True,
                pool="fuchsia.tests",
                test_in_shards=True,
                timeout_secs=1800,
            )),
    )
]