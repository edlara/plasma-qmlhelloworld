import QtQuick 2.2
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1

Item {
    id: generalPage
    width: childrenRect.width
    height: childrenRect.height

    property alias cfg_updateInterval: updateIntervalField.text

    RowLayout {
        ColumnLayout {
            Label {
                text: i18n("Update Interval")
            }
        }
        ColumnLayout {
            TextField {
                id: updateIntervalField
                inputMask: "99"
                inputMethodHints: Qt.ImhDigitsOnly
            }
        }
    }
}
