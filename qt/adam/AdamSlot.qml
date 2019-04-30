import QtQuick 2.4
import QtQuick.Controls 2.0

Item {
    width: 110
    height: 236
    //property int slot_num: index = -1
    property bool is_digital_slot: false

    Rectangle {
        id: rectangle2
        width: 110
        height: 8 * (24 + 3) + 20

        color: "#555555"
        Column {
            id: column
            anchors.horizontalCenterOffset: 0
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 2
            anchors.left: parent.left
            anchors.leftMargin: 5
            spacing: 3
            Text {
                text: "Slot::" + index
                anchors.left: parent.left
                anchors.leftMargin: 5
            }
            Repeater {
                model: ["0","1","2","3","4","5","6","7"]
                AdamChannel { is_digital_channel: is_digital_slot }
            }
        }
    }
}






