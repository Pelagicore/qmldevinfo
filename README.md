QmlDevInfo
==========

A QML plugin to show some information about the target it is running on.

Check DevInfo.qml on how to use it, for now there are 5 properties:

1. softwareVersion - reading PRETTY_NAME and BUILD_ID from /etc/os-release
2. ipAddresses - reading from getifaddrs()
3. ip6Addresses - reading from getifaddrs()
4. nameServer - reading from /etc/resolv.conf
5. defaultGateway - reading from netstat -rn