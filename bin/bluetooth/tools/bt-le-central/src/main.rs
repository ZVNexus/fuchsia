// Copyright 2018 The Fuchsia Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#![deny(warnings)]
#![feature(rustc_private)]

#[macro_use]
extern crate failure;
extern crate fidl;
extern crate fuchsia_app as app;
extern crate fuchsia_async as async;
extern crate fuchsia_zircon as zx;
extern crate futures;
extern crate fidl_bluetooth as bt;
extern crate fidl_bluetooth_gatt as gatt;
extern crate fidl_bluetooth_low_energy as ble;
extern crate getopts;
extern crate parking_lot;

use ble::{CentralDelegateMarker, CentralMarker, CentralProxy, ScanFilter};
use failure::{Error, Fail, ResultExt};
use futures::future;
use futures::prelude::*;
use getopts::Options;

mod common;

use common::central::{CentralState, make_central_delegate};

// TODO(NET-857): Pull these from the fuchsia-bluetooth crate.
use common::error::{BluetoothError, BluetoothFidlError};

fn do_scan(args: &[String], central: &CentralProxy)
    -> (bool, bool, Box<Future<Item = (), Error = Error>>) {
    let mut opts = Options::new();

    opts.optflag("h", "help", "");

    // Options for scan/connection behavior.
    opts.optflag("o", "once", "stop scanning after first result");
    opts.optflag(
        "c",
        "connect",
        "connect to the first connectable scan result",
    );

    // Options for filtering scan results.
    opts.optopt("n", "name-filter", "filter by device name", "NAME");
    opts.optopt("u", "uuid-filter", "filter by UUID", "UUID");

    let matches = match opts.parse(args) {
        Ok(m) => m,
        Err(fail) => {
            return (false, false, Box::new(future::err(fail.into())));
        }
    };

    if matches.opt_present("h") {
        let brief = "Usage: ble-central-tool scan [options]";
        print!("{}", opts.usage(&brief));
        return (
            false,
            false,
            Box::new(future::err(Error::from(BluetoothError))),
        );
    }

    let scan_once: bool = matches.opt_present("o");
    let connect: bool = matches.opt_present("c");

    let uuids = match matches.opt_str("u") {
        None => None,
        Some(val) => Some(vec![
            match val.len() {
                4 => format!("0000{}-0000-1000-8000-00805F9B34FB", val),
                36 => val,
                _ => {
                    println!("invalid service UUID: {}", val);
                    return (
                        false,
                        false,
                        Box::new(future::err(Error::from(BluetoothError))),
                    );
                }
            },
        ]),
    };

    let name = matches.opt_str("n");

    let mut filter = if uuids.is_some() || name.is_some() {
        Some(Box::new(ScanFilter {
            service_uuids: uuids,
            service_data_uuids: None,
            manufacturer_identifier: None,
            connectable: None,
            name_substring: name,
            max_path_loss: None,
        }))
    } else {
        None
    };

    let fut = Box::new(
        central
            .start_scan(&mut filter)
            .map_err(|e| e.context("failed to initiate scan").into())
            .and_then(|status| match status.error {
                None => Ok(()),
                Some(e) => Err(Error::from(BluetoothFidlError::new(*e))),
            }),
    );

    (scan_once, connect, fut)
}

fn do_connect(args: &[String], central: &CentralProxy) -> Box<Future<Item = (), Error = Error>> {
    if args.len() != 1 {
        println!("connect: peer-id is required");
        return Box::new(future::err(Error::from(BluetoothError)));
    }

    let (_, remote) = match zx::Channel::create() {
        Err(e) => {
            return Box::new(future::err(e.into()));
        }
        Ok(x) => x,
    };
    let mut server_end = fidl::endpoints2::ServerEnd::<gatt::ClientMarker>::new(remote);

    Box::new(
        central
            .connect_peripheral(&mut args[0].clone(), &mut server_end)
            .map_err(|e| e.context("failed to connect to peripheral").into())
            .and_then(|status| match status.error {
                None => Ok(()),
                Some(e) => Err(Error::from(BluetoothFidlError::new(*e))),
            }),
    )
}

fn usage(appname: &str) -> () {
    eprintln!(
        "usage: {} <command>
commands:
  scan: Scan for nearby devices and optionally connect to them
  connect: Connect to a peer using its ID",
        appname
    );
}

fn main() -> Result<(), Error> {
    let args: Vec<String> = std::env::args().collect();
    let appname = &args[0];

    if args.len() < 2 {
        usage(appname);
        return Ok(());
    }

    let mut executor = async::Executor::new().context("error creating event loop")?;
    let central_svc = app::client::connect_to_service::<CentralMarker>().context(
        "Failed to connect to BLE Central service",
    )?;

    // Set up the CentralDelegate.
    let (remote, local) = zx::Channel::create().context("failed to create zx channel")?;
    let local = async::Channel::from_channel(local).context(
        "failed to make async channel",
    )?;

    let mut remote_end = fidl::endpoints2::ClientEnd::<CentralDelegateMarker>::new(remote);
    central_svc.set_delegate(&mut remote_end).context(
        "failed to register delegate",
    )?;

    let state = CentralState::new(central_svc);

    let command = &args[1];
    let command_fut = match command.as_str() {
        "scan" => {
            let mut central = state.write();
            let (scan_once, connect, fut) = do_scan(&args[2..], central.get_svc());
            central.scan_once = scan_once;
            central.connect = connect;
            fut
        }
        "connect" => do_connect(&args[2..], state.read().get_svc()),
        _ => {
            println!("Invalid command: {}", command);
            usage(appname);
            return Err(Error::from(BluetoothError));
        }
    };

    // |delegate_fut| can never fail but we map its error type to a placeholder to coerce the
    // types.
    let delegate_fut =
        make_central_delegate(state, local).map_err(|_| BluetoothError::new().into());
    let fut = command_fut.and_then(|_| delegate_fut);
    executor.run_singlethreaded(fut).map_err(Into::into)
}
