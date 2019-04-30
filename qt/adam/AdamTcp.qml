import QtQuick 2.4
import QtQuick.Controls 2.0

Item {
    id: root
    width: 900
    height: 800

    property bool isConnected: false
    signal eventButton(string message)

    Rectangle {
        id: rectangle
        anchors.fill: parent
        color: "#333333"
        Rectangle {
            id: rectangle1
            color: "#777777"
            width: 400
            height: 26
            border.color: "white"
            border.width: 1
            anchors.left: parent.left
            anchors.leftMargin: 5
            anchors.top: parent.top
            anchors.topMargin: 5
            Row {
                id: row
                anchors.rightMargin: 5
                anchors.leftMargin: 5
                anchors.fill: parent
                spacing: 5
                Text {
                    text: qsTr("IP Address:")
                    horizontalAlignment: Text.AlignRight
                    anchors.verticalCenter: parent.verticalCenter
                }
                TextField {
                    id: txtIpAddress
                    objectName: "txtIpAddress"
                    color: "#000000"
                    text: qsTr("10.10.10.10")
                    rightPadding: 0
                    bottomPadding: 0
                    topPadding: 0
                    font.pointSize: 9
                    anchors.verticalCenter: parent.verticalCenter
                    width: 150
                    height: 22
                }
                Rectangle {
                    id: rectStatus
                    objectName: "rectStatus"
                    width: 20
                    height: 20
                    radius: 10
                    anchors.verticalCenter: parent.verticalCenter
                    color: isConnected ? "green" : "black"
                    border.color: "white"
                    border.width: 1
                }
                Button {
                    id: btnConnect
                    height: 22
                    objectName: "btnConnect"
                    text: qsTr(isConnected ? "disconnect" : "connect")
                    anchors.verticalCenter: parent.verticalCenter

                    onClicked: eventButton("Adam-Connect-" + !isConnected);
                }
            }
        }
        Button {
            id: btnSend
            objectName: "btnSend"
            width: 200
            height: 24
            text: qsTr("send")
            anchors.verticalCenter: rectangle1.verticalCenter
            anchors.left: rectangle1.right
            anchors.leftMargin: 5

            onClicked:  eventButton("Adam-Send-0")
        }


        Column {
            id: slots
            spacing: 5
            anchors.left: parent.left
            anchors.leftMargin: 5
            anchors.top: rectangle1.bottom
            anchors.topMargin: 5
            Repeater {
                model: [true, false]
                AdamPanel {
                    is_digital_panel: modelData
                }
            }
        }
    }
}
