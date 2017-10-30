QmlDevInfo
==========

A QML plugin to show some information about the target it is running on.

## Installation

    mkdir build
    cd build
    qmake ..
    make
    sudo make install

## QMake flags

The plugin can be configured to enable features. Currently supported features 
are:

* ENABLE_EXAMPLES -- enables the build of currently available examples. 

## Usage

Check `example` folder on how to use it, for now there are 6 properties:

1. softwareVersion -- reading `PRETTY_NAME` from `/etc/os-release`
2. buildId -- reading `BUILD_ID` from `/etc/os-release`
2. ipAddresses -- reading from `getifaddrs()`
3. ip6Addresses -- reading from `getifaddrs()`
4. nameServer -- reading from `/etc/resolv.conf`
5. defaultGateway - reading from `netstat -rn`

You also can find a dummy file in `dummyimports` which you can use for
your code instead of the C++ plugin while developing.

## License

This software is Free Software licensed under the Mozilla Public License 2.0
