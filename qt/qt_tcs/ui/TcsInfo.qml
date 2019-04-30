import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Controls 2.5

Item {
    id: root
    width: 340
    height: 300
    Rectangle {
        id: rectangle
        anchors.fill: parent
        anchors.margins: 5
        color: "#555555"
        Column {
            anchors.top: parent.top
            anchors.margins: 10

            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 2
            DataField {
                id: dfDateTime
                objectName: "dfDateTime"
                header: "Дата/время:"
                value: "1979.09.14 01:00"
                headerAlignment: Text.AlignRight
                isCombo: false
                isEditable: false
            }
            DataField {
                id: dfCustomer
                objectName: "dfCustomer"
                header: "Заказчик:"
                value: "Лукойл ЗС"
                headerAlignment: Text.AlignRight
                isCombo: true
            }
            DataField {
                id: dfOrder
                objectName: "dfOrder"
                header: "Наряд-заказ:"
                value: "1122334455"
                headerAlignment: Text.AlignRight
                isCombo: false
            }
            ToolSeparator {
                width: 315
                height: 10
                orientation: Qt.Horizontal
            }
            DataField {
                id: dfProducer
                objectName: "dfProducer"
                header: "Производитель:"
                value: "ООО \"ИРЗ\""
                headerAlignment: Text.AlignRight
                isCombo: true
            }
            DataField {
                id: dfType
                objectName: "dfType"
                header: "Тип:"
                value: "ИРЗ-500-12-БП"
                headerAlignment: Text.AlignRight
                isCombo: true
            }
            DataField {
                id: dfNomI
                objectName: "dfNomI"
                header: "Номинал I,А:"
                value: "150"
                headerAlignment: Text.AlignRight
                isCombo: false
            }
            DataField {
                id: dfNomP
                objectName: "dfNomP"
                header: "Номинал P,кВт:"
                value: "420"
                headerAlignment: Text.AlignRight
                isCombo: false
            }
            DataField {
                id: dfMaxI
                objectName: "dfMaxI"
                header: "Максимальный I,А:"
                value: "150"
                headerAlignment: Text.AlignRight
                isCombo: false
            }
            DataField {
                id: dfSecU
                objectName: "dfSecU"
                header: "Втор.обмотка U,В:"
                value: "950"
                headerAlignment: Text.AlignRight
                isCombo: false
            }
            DataField {
                id: dfMaxSpeed
                objectName: "dfMaxSpeed"
                header: "Макс.скорость,об/мин:"
                value: "500"
                headerAlignment: Text.AlignRight
                isCombo: false
            }
            DataField {
                id: dfMinSpeed
                objectName: "dfMinSpeed"
                header: "Мин.скорость,об/мин:"
                value: "3000"
                headerAlignment: Text.AlignRight
                isCombo: false
            }
        }
    }



}
