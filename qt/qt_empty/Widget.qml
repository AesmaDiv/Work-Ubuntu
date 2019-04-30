import QtQuick 2.0
import QtQuick.Controls 2.5

Item {
    id: root
    width: 200
    height: 50

    signal onEvent(variant array)

    Rectangle {
        id: rectWidget
        objectName: "rectWidget"
        anchors.fill: parent
        color: "red"

        Button {
            id: btnWidget
            objectName: "btnWidget"
            width: 100
            height: 30
            text: qsTr("Widget")
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter

            onClicked: root.onEvent([1, 2, 3, 4, 5, 6, 7, 8, 9])
        }
    }
}

