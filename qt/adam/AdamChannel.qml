import QtQuick 2.4
import QtQuick.Controls 2.0

Item {
    property bool state: true
    property bool is_digital_channel: true

    width: 100
    height: 24
    Rectangle {
        id: rect_root
        width: 100
        height: 24
        color: "#777777"
        Row {
            id: model_root
            width: 100
            height: 24
            Text {
                id: model_label
                text: "ch::" + index
                verticalAlignment: Text.AlignVCenter
                anchors.verticalCenter: parent.verticalCenter
                anchors.right: rect_value.left
                anchors.rightMargin: 5
                width: 30
                height: 22
            }
            Rectangle {
                id: rect_value
                width: is_digital_channel ? 22 : 50
                height: 24
                color: "transparent"
                anchors.right: parent.right
                anchors.rightMargin: 2

                TextField {
                    id: model_value
                    objectName: "txtChannel0"
                    color: "#000000"
                    text: qsTr("-----")
                    padding: 0
                    anchors.verticalCenter: parent.verticalCenter
                    font.pointSize: 9
                    anchors.right: parent.right
                    width: 50
                    height: 22
                    visible: !is_digital_channel
                }
                Rectangle {
                    id: model_digital
                    objectName: "txtChannel0"
                    width: 20
                    height: 20
                    radius: 10
                    color:  state ? "green" : "black"
                    border.color: "white"
                    border.width: 1
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.right: parent.right
                    visible: is_digital_channel
                }
            }
        }
    }
}
