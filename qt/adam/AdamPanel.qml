import QtQuick 2.4
import QtQuick.Controls 2.0

Item {
    width: 890
    height: 266

    property bool is_digital_panel: true

    Rectangle {
        id: rectAnalog
        anchors.fill: parent
        anchors.left: rectangle1.left
        anchors.top: rectangle1.bottom
        color: "#777777"
        border.color: "white"
        border.width: 1
        Text {
            id: label
            text: is_digital_panel ? "Digital" : "Analog"
            verticalAlignment: Text.AlignVCenter
            width: 200
            height: 18
            anchors.top: parent.top
            anchors.topMargin: 5
            anchors.left: parent.left
            anchors.leftMargin: 10
        }
        Row {
            anchors.left: parent.left
            anchors.leftMargin: 5
            anchors.top: label.bottom
            anchors.topMargin: 0
            Repeater {
                model: ["0","1","2","3","4","5","6","7"]
                delegate: AdamSlot { is_digital_slot: is_digital_panel }
            }
        }
    }
}



















/*##^## Designer {
    D{i:1;anchors_height:246;anchors_width:880}
}
 ##^##*/
