import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtQuick.Controls 1.4

Window {
    signal onEvent(string message)
    signal onMenuButtonClick(string message)

    id: root
    objectName: "wndMain"
    visible: true
    width: 1024
    height: 768
    color: "#858585"
    title: qsTr("Hello World")

    RoundButton {
        id: roundButton
        x: 5
        y: 5
        display: AbstractButton.IconOnly
        icon.source: "qrc:/images/LogoSymbol.png"
        icon.width: 30
        icon.height: 30
        onClicked: root.onEvent("Round button clicked");
    }
    Switch {
        id: switchTestList
        x: 151
        y: 29
        checked: swipeView.currentIndex
    }
    Rectangle {
        width: 340
        height: 700
        color: "#00000000"
        anchors.left: parent.left
        anchors.leftMargin: 5
        anchors.top: roundButton.bottom
        anchors.topMargin: 5
        border.color: "white"
        border.width: 1
        clip: true

        SwipeView {
            id: swipeView
            anchors.fill: parent
            currentIndex: switchTestList.checked ? 1 : 0

            TestList {
                id: testList
                objectName: "testList"
                width: 340
                height: 700
            }
            TcsInfo {
                id: tcsInfo
                objectName: "tcsInfo"
                width: 340
                height: 700
            }
        }
    }
}

