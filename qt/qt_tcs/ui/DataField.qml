import QtQuick 2.0
import QtQuick.Controls 2.5

Row {
    id: root
    property string header: "Заголовок"
    property string value: "значение"
    property int headerAlignment: Text.AlignLeft
    property int valueAlignment: Text.AlignLeft
    property bool isCombo: true
    property bool isEditable: true

    width: 315
    height: 22
    spacing: 5
    Text {
        id: txtHeader
        text: qsTr(header)
        horizontalAlignment: headerAlignment
        anchors.right: rectValue.left
        anchors.rightMargin: 10
        anchors.left: root.left
        anchors.leftMargin: 5
        anchors.verticalCenter: root.verticalCenter
        font.pixelSize: 12
    }
    Rectangle {
        id: rectValue
        width: 160
        height: 22
        anchors.right: root.right
        anchors.rightMargin: 0
        anchors.verticalCenter: root.verticalCenter
        TextField {
            id: txtValue
            text: qsTr(value)
            anchors.fill: rectValue
            font.pixelSize: 12
            padding: 0
            horizontalAlignment: valueAlignment
            visible: !isCombo
        }
        ComboBox {
            id: cmbValue
            currentIndex: 0
            anchors.fill: rectValue
            font.pixelSize: 12
            padding: 0
            visible: isCombo
            textRole: "displayLabel"
            displayText: qsTr(value)
            editable: isEditable
        }
    }
}

