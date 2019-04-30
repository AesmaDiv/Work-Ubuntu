import QtQuick.Window 2.12
import QtQuick 2.12
import QtQuick.Controls 2.5


Window {
    id: window
    objectName: "wndMain"
    visible: true
    width: 510
    height: 660
    title: qsTr("Hello World")

    signal onEvent(string message)

    Button {
        id: button
        text: qsTr("Button")
        anchors.top: parent.top
        anchors.topMargin: 50
        anchors.left: parent.left
        anchors.leftMargin: 50

        onClicked: onEvent("Button clicked");
    }

    Widget {
        id: widget
        objectName: "Widget"
        width: 200
        height: 50
        anchors.rightMargin: 0
        anchors.bottomMargin: 507
        anchors.leftMargin: 264
        anchors.topMargin: 0
    }
}






/*##^## Designer {
    D{i:1;anchors_x:32;anchors_y:30}
}
 ##^##*/
