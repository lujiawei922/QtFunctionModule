import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import "./Classical"
Window {
    visible: true
    width: 1920
    height: 720
    color: "black"

    Item{
        //按键事件
        anchors.fill: parent
        focus: true
        Keys.onPressed:{
        }
    }

    SwipeView {
        id: swipeView
        anchors.fill: parent
        //滑动方向
        orientation: Qt.Horizontal
        clip: true

        Classical {
            width: 1920
            height: 720
            visible: true
        }
    }
}
