import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Controls 2.5

Rectangle {
    signal onSelectionChanged(variant current_item)
    signal onFilter(string message)
    signal onItemClicked(string message)

    id: root
    width: 340
    height: 510
    color: "#555555"

    TextField {
        id: txtFilter
        objectName: "txtFilter"
        height: 24
        text: qsTr("Input filter")
        anchors.top: parent.top
        anchors.topMargin: 8
        anchors.left: parent.left
        anchors.leftMargin: 8
        anchors.right: btnFilter.left
        anchors.rightMargin: 8
        padding: 0
        selectByMouse: true
    }
    Button {
        id: btnFilter
        objectName: "btnFilter"
        x: 258
        width: 24
        height: 24
        text: qsTr("")
        anchors.top: parent.top
        anchors.topMargin: 8
        anchors.right: parent.right
        anchors.rightMargin: 8
        rightPadding: 0
        leftPadding: 0
        padding: 3
        icon.name: "filter"
        icon.source: "qrc:/images/magnifier.png"
        display: AbstractButton.IconOnly

        onClicked: onFilter(txtFilter.text)
    }

    ListView {
        id: testListView
        objectName: "testListView"
        x: 5
        y: 38
        width: 320
        height: 454
        model: testListViewModel
        delegate: TestListRow {
            MouseArea {
                anchors.fill: parent
                onClicked: onItemClicked(modelData)
            }
        }
    }

}
