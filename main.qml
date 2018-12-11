import QtQuick 2.2
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Component {
        id: highlightBox
        Rectangle {
            width: root.cellWidth
            height: root.cellHeight
            color: "#C0FFFF88"
            x: root.currentItem.x
            y: root.currentItem.y
            Behavior on x { SmoothedAnimation {duration: 100}}
            Behavior on y { SmoothedAnimation {duration: 100}}
        }
    }

    Component {
        id: itemDelegate
        Rectangle {
            id: wrapper

            MouseArea {
                anchors.fill: parent
                onClicked: wrapper.GridView.view.currentIndex = index
            }

            width: root.cellWidth
            height: root.cellHeight
            color: model.display !== "0" ? model.decoration : "#00000000"
            Text {
                anchors.centerIn: parent
                text: model.display
            }
        }
    }

    GridView {
        id: root
        interactive: false

        leftMargin: 25
        topMargin: 25
        rightMargin: 25
        bottomMargin: 25

        cellWidth: (parent.width - 50) / 9
        cellHeight: (parent.height - 50) / 9

        highlight: highlightBox
        highlightFollowsCurrentItem: false

        anchors.fill: parent
        anchors.centerIn: parent
        model: SudokuViewModel

        focus: true

        delegate: itemDelegate
    }
}
