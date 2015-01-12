import QtQuick 2.0
import com.pelagicore.qmldevinfo 0.1;

Item {
    Column {
        Text {
            text: "IPV4: " + devinfo.ipAddress
        }

        Text {
            text: "IPV6: " + devinfo.ipAddress6
        }
    }

    DevInfo {
        id: devinfo
    }
}
