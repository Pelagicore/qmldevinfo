import QtQuick 2.0
import QtQuick.Controls 1.2

ApplicationWindow {
    id: window
    visible: true
    width: 400
    height: 462

    menuBar: MenuBar {

        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("Exit")
                shortcut: "Ctrl+Q"
                onTriggered: Qt.quit()
            }
        }
    }

    DevInfo {}
}
