import QtQuick 2.0
import "./module"

Item {
    property int itemX: 646
    property int itemY: 171
    property int itemWidth: 628
    property int itemHeight: 352

    property var menuPage: [navigation,music,phone,setting,carWaring]
    property var menuTexts: [qsTr("导航"),qsTr("音乐"),qsTr("电话"),qsTr("设置"),qsTr("预警")]

    Component.onCompleted: {//初始化本页面
        menuText.text = menuTexts[0]
        navigation.visible = true
    }

    MenuIcon{
        //顶部图标区域
        id: menuIcon
        itemX: 660
        itemY: 111
        itemWidth: 545
        itemHeight: 54
    }

    Item { //顶部文字图标区域
        id: topmenuText
        x: itemX
        y: 200
        width: itemWidth
        height: 60
        Image {
            x: (parent.width - width) / 2
            source: "qrc:/Image/Common/Menu/BottomLine.png"
        }
        Text {
            id: menuText
            x: (itemWidth - width)/2
            y: -25
            //font.family: defaultFontFamily
            font.pointSize: 30
            color: "white"
        }
    }

    Item{
        x:itemX
        y:itemY + topmenuText.height + 10
        width: itemWidth
        height: itemHeight

        Navigation{//导航
            id:navigation
            anchors.fill: parent
            visible: false
            onVisibleChanged: {
                if(visible){
                    navigation.play()
                }else{
                    navigation.pause()
                }
            }
        }

        MusicModel2{
            id: music
            width: parent.width
            height: parent.height
            x: 10
            y: 30
            visible: false
        }

        Phone{//电话
            id: phone
            itemYPos: 0
            width: itemWidth
            height: itemHeight
            phoneBookShowNumbers: 3
            visible: false
        }

        Setting{//设置
            id: setting
            visible: false
            width: parent.width
            height: 360
        }

        CarWaring{//车辆报警
            id: carWaring
            visible: false
            anchors.fill: parent
        }
    }
}
