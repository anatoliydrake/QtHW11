import QtQuick 2.15

BorderImage {
    property alias text: txt.text
    signal clicked
    source: "qrc:///img/red-button.png"

    Text {
        id: txt
        color: "white"
        anchors.centerIn: parent
    }

    MouseArea {
        anchors.fill: parent
        onClicked: parent.clicked()
        onPressed: {}
        onReleased: {}
    }
}
