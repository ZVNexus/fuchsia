// Copyright 2018 The Fuchsia Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef GARNET_EXAMPLES_BLUETOOTH_BT_BEACON_READER_APP_H_
#define GARNET_EXAMPLES_BLUETOOTH_BT_BEACON_READER_APP_H_

#include <bluetooth_low_energy/cpp/fidl.h>
#include <lib/async-loop/cpp/loop.h>

#include "lib/app/cpp/startup_context.h"
#include "lib/fxl/macros.h"

namespace bt_beacon_reader {

class App final : public bluetooth_low_energy::CentralDelegate {
 public:
  App(async::Loop* loop, bool just_tilts);

  void StartScanning();

 private:
  // bluetooth_low_energy::CentralDelegate overrides:
  void OnScanStateChanged(bool scanning);
  void OnDeviceDiscovered(bluetooth_low_energy::RemoteDevice device);
  void OnPeripheralDisconnected(::fidl::StringPtr identifier);

  async::Loop* const loop_;
  std::unique_ptr<component::StartupContext> context_;
  bluetooth_low_energy::CentralPtr central_;

  // Local CentralDelegate binding.
  fidl::Binding<bluetooth_low_energy::CentralDelegate> central_delegate_;

  bool just_tilts_;

  FXL_DISALLOW_COPY_AND_ASSIGN(App);
};

}  // namespace bt_beacon_reader

#endif  // GARNET_EXAMPLES_BLUETOOTH_BT_BEACON_READER_APP_H_
