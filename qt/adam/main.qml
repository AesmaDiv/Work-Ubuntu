import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5



Window {
    id: window
    objectName: "wndMain"
    visible: true
    width: 910
    height: 810
    title: qsTr("Hello World")

    Column {
        id: column
        spacing: 5
        AdamTcp {
            id: widgetAdam
            objectName: "widgetAdam"
            anchors.left: parent.left
            anchors.leftMargin: 5
            anchors.top: widgetRiz.bottom
            anchors.topMargin: 5

        }
    }
}

