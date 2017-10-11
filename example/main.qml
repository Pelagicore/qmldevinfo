/* Copyright 2014-2015 Pelagicore Group */
import QtQuick 2.6;
import QtQuick.Controls 2.2;
import com.pelagicore.qmldevinfo 0.1;

ApplicationWindow {
    height: 600
    width: 600
    visible: true

    Rectangle {
        color: "white"
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        height: grid.height + 20
        width: parent.width

        Item {
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            anchors.margins: 20
            anchors.bottomMargin: 0

            Grid {
                id: grid
                columns: 2
                spacing: 10
                anchors.bottom: parent.bottom

                Text { text: "Version:" }
                Text { text: devinfo.softwareVersion ? devinfo.softwareVersion : " " }

                Text { text: "Build:" }
                Text { text: devinfo.buildId ? devinfo.buildId : " " }

                Text { text: "IPv4:" }
                Text { text: devinfo.ipAddresses.length ? devinfo.ipAddresses.join("\n") : " " }

                Text { text: "IPv6:" }
                Text { text: devinfo.ip6Addresses.length ? devinfo.ip6Addresses.join("\n") : " " }

                Text { text: "DNS:" }
                Text { text: devinfo.nameServer ? devinfo.nameServer : " " }

                Text { text: "Gateway:" }
                Text { text: devinfo.defaultGateway ? devinfo.defaultGateway : " " }
            }
        }

        DevInfo {
            id: devinfo
        }

    }
}
