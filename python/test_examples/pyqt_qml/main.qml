import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 400
    height: 300
    title: "PyQt QML Example"

    Rectangle {
        width: 400
        height: 300
        color: "lightgray"

        Text {
            anchors.centerIn: parent
            text: backend.message
            font.pixelSize: 20
        }

        Button {
            anchors.centerIn: parent
            text: "Click Me"
            onClicked: {
                backend.updateMessage()
            }
        }
    }
}
