import QtQuick 2.0
import com.pelagicore.qmldevinfo 0.1;

Item {
    Column {

        Text {
            text: "Version: \t" + devinfo.softwareVersion
        }

        Text {
            text: "IPV4: \t" + devinfo.ipAddresses.join("\n\t")
        }

        Text {
            text: "IPV6: \t" + devinfo.ip6Addresses.join("\n\t")
        }

        Text {
            text: "DNS: \t" + devinfo.nameServer
        }

        Text {
            text: "Gateway:\t" + devinfo.defaultGateway
        }
    }

    DevInfo {
        id: devinfo
    }
}
