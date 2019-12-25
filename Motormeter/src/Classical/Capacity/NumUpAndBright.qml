import QtQuick 2.0

Item {
    property int maxValue: 8000      // 最大值,一定得是0-9999范围之间，不在此范围需要自己做转换
    property int currentValue: 0     // 当前值
    property double initOpacity: 0.3 // 初始所有文本透明度
    property int initScanle: 1.0     // 初始放大倍数
    property double scanleValue: 1.8 // 设置放大倍数
    property double duration: 1   // 设置连续缩放对象之间的间隔距离

    property var texts: [text0,text1,text2,text3,text4]

    property int interraval : maxValue / (texts.length - 1) // 计算间隔大小

    onCurrentValueChanged: {
        updateEffect()
    }

    Component.onCompleted: {
       updateEffect()
    }

    function updateEffect(){
        var temp = currentValue / interraval // 获取指针间隔数字位置
        for(var i=0;i<texts.length;i++){
            if(temp>i-duration||temp<i+duration){
                if(temp>i){//圆弧上半部分
                    texts[i].opacity =  1 - ((temp - i )/duration)*(1-initOpacity) // 百分比计算透明度
                    texts[i].scale =  scanleValue - ((temp - i )/duration)*(scanleValue-initScanle)
                }else{//圆弧下半部分
                    texts[i].opacity =  initOpacity + ((temp - i  + duration)/duration)*(1-initOpacity) // 百分比计算透明度
                    texts[i].scale = initScanle + ((temp - i  +duration)/duration)*(scanleValue-initScanle)
                }
            }else{
                texts[i].opacity = initOpacity
            }
        }
    }

    Text {
            id: text0
            x: 1400
            y: 460
            width: 24
            height: 24
            color: "white"
            text: "-20"
//            font.family: fontFamily
            opacity: initOpacity
            lineHeight: 1
            font.bold: true
            clip: false
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            elide: Text.ElideNone
            font.pixelSize: 26
            transform: Scale{
                origin.x: parent.width / 2
                origin.y: parent.height / 2
            }
            scale: initScanle
        }

        Text {
            id: text1
            x: 1375
            y: 345
            width: 24
            height: 24
            color: "white"
            text: "0"
//            font.family: fontFamily
            elide: Text.ElideNone
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            clip: false
            lineHeight: 1
            opacity: initOpacity
            font.pixelSize: 26
            font.bold: true
            transform: Scale{
                origin.x: parent.width / 2
                origin.y: parent.height / 2
            }
            scale: initScanle
        }

        Text {
            id: text2
            x: 1405
            y: 234
            width: 24
            height: 24
            color: "white"
            text: "20"
//            font.family: fontFamily
            elide: Text.ElideNone
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            clip: false
            lineHeight: 1
            opacity: initOpacity
            font.pixelSize: 26
            font.bold: true
            transform: Scale{
                origin.x: parent.width / 2
                origin.y: parent.height / 2
            }
            scale: initScanle
        }

        Text {
            id: text3
            x: 1480
            y: 163
            width: 24
            height: 24
            color: "white"
            text: "40"
//            font.family: fontFamily
            elide: Text.ElideNone
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            clip: false
            lineHeight: 1
            opacity: initOpacity
            font.pixelSize: 26
            font.bold: true
            transform: Scale{
                origin.x: parent.width / 2
                origin.y: parent.height / 2
            }
            scale: initScanle
        }

        Text {
            id: text4
            x: 1585
            y: 140
            width: 24
            height: 24
            color: "white"
            text: "60"
//            font.family: fontFamily
            elide: Text.ElideNone
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            clip: false
            lineHeight: 1
            opacity: initOpacity
            font.pixelSize: 26
            font.bold: true
            transform: Scale{
                origin.x: parent.width / 2
                origin.y: parent.height / 2
            }
            scale: initScanle
        }
}
