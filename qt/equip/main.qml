import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5

Window {
    visible: true
    width: 500
    height: 300
    title: qsTr("Hello World")

    property bool isConnected: false
    signal eventButton(string message)

    Rectangle {
        id: rectRoot
        anchors.fill: parent
        color: "#999999"

        Rectangle {
            id: rectLabel
            color: "#777777"
            anchors.top: parent.top
            anchors.topMargin: 5
            anchors.left: parent.left
            anchors.leftMargin: 5
            width: 200
            height: 70

            Row {
                id: row
                spacing: 5
                padding: 5

                Column {
                    id: column
                    spacing: 5
                    Text {
                        text: qsTr("Тип:")
                        anchors.right: parent.right
                        anchors.rightMargin: 0
                        font.pointSize: 10
                    }
                    Text {
                        text: qsTr("Наряд-заказ:")
                        anchors.right: parent.right
                        anchors.rightMargin: 0
                        font.pointSize: 10
                    }
                    Text {
                        text: qsTr("Заводской №:")
                        anchors.right: parent.right
                        anchors.rightMargin: 0
                        font.pointSize: 10
                    }
                }
                Column {
                    spacing: 5
                    Text {
                        text: qsTr("ТМС-01-БУ2")
                        font.pointSize: 10
                    }
                    Text {
                        text: qsTr("1127899")
                        font.pointSize: 10
                    }
                    Text {
                        text: qsTr("ЗН 125456-45")
                        font.pointSize: 10
                    }
                }
            }
        }

        Rectangle {
            id: rectangle
            height: 24
            color: "#555555"
            anchors.right: parent.right
            anchors.rightMargin: 5
            anchors.left: rectLabel.right
            anchors.leftMargin: 5
            anchors.top: parent.top
            anchors.topMargin: 5

            Row {
                id: row1
                anchors.right: parent.right
                anchors.rightMargin: 10
                anchors.verticalCenter: parent.verticalCenter
                spacing: 10
                Text {
                    text: qsTr("мегаомметр")
                    anchors.verticalCenter: parent.verticalCenter
                }
                Button {
                    id: btnConnection
                    text: qsTr(isConnected ? "отключить" : "подключить")
                    font.pointSize: 10
                    height: 20
                    width: 110

                    onClicked: eventButton("Connection-" + isConnected.toString());
                }
                Rectangle {
                    id: rectConnectionState
                    width: 20
                    height: 20
                    radius: 10
                    color: isConnected ? "green" : "grey"
                    border.color: "white"
                    border.width: 2
                }
            }
        }

        Column {
            id: column1
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: rectLabel.bottom
            anchors.topMargin: 10
            spacing: 5
            Row {
                spacing: 5
                Rectangle {
                    color: "#555555"
                    border.color: "black"
                    border.width: 1
                    width: 150
                    height: 24

                }
                Rectangle {
                    color: "#555555"
                    border.color: "black"
                    border.width: 1
                    width: 100
                    height: 24
                    Text {
                        text: qsTr("R изоляции")
                        font.pointSize: 10
                        font.italic: true
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter: parent.verticalCenter
                    }
                }
                Rectangle {
                    color: "#555555"
                    border.color: "black"
                    border.width: 1
                    width: 100
                    height: 24
                    Text {
                        text: qsTr("Температура")
                        font.pointSize: 10
                        font.italic: true
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter: parent.verticalCenter
                    }
                }
                Rectangle {
                    color: "#555555"
                    border.color: "black"
                    border.width: 1
                    width: 100
                    height: 24
                    Text {
                        text: qsTr("Давление")
                        font.pointSize: 10
                        font.italic: true
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter: parent.verticalCenter
                    }
                }
            }
            Row {
                spacing: 5
                Rectangle {
                    id: rectangle2
                    color: "#555555"
                    border.color: "black"
                    border.width: 1
                    width: 150
                    height: 24
                    Text {
                        text: qsTr("Блок сопряжения")
                        anchors.right: parent.right
                        anchors.rightMargin: 10
                        font.pointSize: 10
                        font.italic: true
                        anchors.verticalCenter: parent.verticalCenter
                    }

                }
                Rectangle {
                    color: "#555555"
                    border.color: "black"
                    border.width: 1
                    width: 100
                    height: 24
                    Text {
                        id: txtRiz
                        text: qsTr("-----")
                        font.pointSize: 12
                        font.italic: true
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter: parent.verticalCenter
                    }
                }
                Rectangle {
                    color: "#555555"
                    border.color: "black"
                    border.width: 1
                    width: 100
                    height: 24
                    Text {
                        id: txtTemp_BST
                        text: qsTr("--.-")
                        font.pointSize: 12
                        font.italic: true
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter: parent.verticalCenter
                    }
                }
                Rectangle {
                    color: "#555555"
                    border.color: "black"
                    border.width: 1
                    width: 100
                    height: 24
                    Text {
                        id: txtPress_BST
                        text: qsTr("--.--")
                        font.pointSize: 12
                        font.italic: true
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter: parent.verticalCenter
                    }
                }
            }
            Row {
                spacing: 5
                Rectangle {
                    id: rectangle1
                    color: "#555555"
                    border.color: "black"
                    border.width: 1
                    width: 150
                    height: 24
                    Text {
                        text: qsTr("Образец")
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.right: parent.right
                        anchors.rightMargin: 10
                        font.pointSize: 10
                        font.italic: true
                    }
                }
                Rectangle {
                    color: "#777777"
                    border.color: "black"
                    border.width: 1
                    width: 100
                    height: 24

                }
                Rectangle {
                    color: "#555555"
                    border.color: "black"
                    border.width: 1
                    width: 100
                    height: 24
                    Text {
                        id: txtTemp_STD
                        text: qsTr("--.-")
                        font.pointSize: 12
                        font.italic: true
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter: parent.verticalCenter
                    }
                }
                Rectangle {
                    color: "#555555"
                    border.color: "black"
                    border.width: 1
                    width: 100
                    height: 24
                    Text {
                        id: txtPress_STD
                        text: qsTr("--.--")
                        font.pointSize: 12
                        font.italic: true
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter: parent.verticalCenter
                    }
                }
            }

            Button {
                id: btnMeasure
                text: qsTr("Начать замер")
                checkable: true
                anchors.right: parent.right
                anchors.rightMargin: 0
                anchors.left: parent.left
                anchors.leftMargin: 0
                height: 24
                onClicked: eventButton("Measuring-" + checked.toString());
            }
            Button {
                id: btnSave
                text: qsTr("Сохранить")
                anchors.right: parent.right
                anchors.rightMargin: 0
                anchors.left: parent.left
                anchors.leftMargin: 0
                height: 24
                onClicked: eventButton("Save-0")
            }
        }

    }
}
