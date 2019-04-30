import QtQuick 2.12
import QtQml 2.3

Item {
    signal onRowClicked(string message)

    id: root
    width: 320
    height: 26

    property var locale: Qt.locale()
    property int recId: 9999
    property string dateTime: "2015.09.15 14:56"
    property string order: "0123456789"
    property string serial: "0123456789-ABC"
    property color txt_color: mouseArea.containsMouse ? "black" : "white"

    property variant info: [recId, dateTime, order, serial]

    MouseArea {
        id: mouseArea
        anchors.fill: root
        hoverEnabled: true
        onClicked: onRowClicked("click")
    }
    Rectangle {
        anchors.fill: parent
        anchors.margins: 2
        color: "#AAAAAA"
        opacity: mouseArea.containsMouse ? 0.8 : 0
        radius: 3
    }
    Row {
        anchors.leftMargin: 5
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        spacing: 2
        Text {
            id: txtId
            width: 30
            objectName: "txtId"
            color: txt_color
            text: qsTr(recId.toString())
            anchors.verticalCenter: parent.verticalCenter
            font.pointSize: 8
            font.family: "Verdana"
        }
        Text {
            id: txtDateTime
            width: 100
            objectName: "txtDateTime"
            color: txt_color
            text: dateTime
            anchors.verticalCenter: parent.verticalCenter
            font.pointSize: 8
            font.family: "Verdana"
        }
        Text {
            id: txtOrder
            width: 70
            objectName: "txtOrder"
            color: txt_color
            text: qsTr(order)
            anchors.verticalCenter: parent.verticalCenter
            font.pointSize: 8
            font.family: "Verdana"
        }
        Text {
            id: txtSerial
            width: 100
            objectName: "txtSerial"
            color: txt_color
            text: qsTr(serial)
            anchors.verticalCenter: parent.verticalCenter
            font.pointSize: 8
            font.family: "Verdana"
        }
    }
}
