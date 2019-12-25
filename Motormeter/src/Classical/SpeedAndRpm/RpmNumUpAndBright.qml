import QtQuick 2.0

Item {
    property int maxValue: 9000      // 最大值
    property int currentValue: 0     // 当前值
    property double initOpacity: 0.3 // 初始所有文本透明度
    property int initScanle: 1.0     // 初始放大倍数
    property int scanleValue: 2.0    // 设置放大倍数
    property double duration: 2   // 设置连续缩放对象之间的间隔距离
    property var texts: [text0,text1,text2,text3,text4,text5,text6,text7,text8,text9]

    property int interraval : maxValue / (texts.length - 1) // 计算间隔大小


    onCurrentValueChanged: {
       updateEffect()
    }

    Component.onCompleted: {
        updateEffect() // 组件构建完成后调用效果设置
    }

    function updateEffect(){
            // 获取指针间隔数字位置
            var temp = currentValue / interraval
            for(var i=0;i<texts.length;i++){
                if(temp>i-duration||temp<i+duration){
                    if(temp>i){
                        //圆弧上半部分
                        texts[i].opacity =  1 - ((temp - i )/duration)*(1-initOpacity) // 百分比计算透明度
                        texts[i].scale =  scanleValue - ((temp - i )/duration)*(scanleValue-initScanle)
                    }else{
                        //圆弧下半部分
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
            x: 155
            y: 510
            color: "white"
            width: 16
            height: 26
            text: "0"
            //font.family: fontFamily
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
            x: 93
            y: 406
            width: 16
            height: 26
            color: "#ffffff"
            text: "1"
            //font.family: fontFamily
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
            x: 93
            y: 285
            width: 16
            height: 26
            color: "#ffffff"
            text: "2"
            //font.family: fontFamily
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
            x: 156
            y: 183
            width: 16
            height: 26
            color: "#ffffff"
            text: "3"
            //font.family: fontFamily
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
            x: 254
            y: 135
            width: 16
            height: 26
            color: "#ffffff"
            text: "4"
            //font.family: fontFamily
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
            id: text5
            x: 371
            y: 135
            width: 16
            height: 26
            color: "#ffffff"
            text: "5"
            //font.family: fontFamily
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
            id: text6
            x: 468
            y: 184
            width: 16
            height: 26
            color: "#ffffff"
            text: "6"
            //font.family: fontFamily
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
            id: text7
            x: 530
            y: 285
            width: 16
            height: 26
            color: "#ffffff"
            text: "7"
            //font.family: fontFamily
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
            id: text8
            x: 530
            y: 406
            width: 16
            height: 26
            color: "#ffffff"
            text: "8"
            //font.family: fontFamily
            elide: Text.ElideNone
            verticalAlignment: Text.AlignVCenter
            clip: false
            horizontalAlignment: Text.AlignHCenter
            lineHeight: 1
            opacity: initOpacity
            font.bold: true
            font.pixelSize: 26
            transform: Scale{
                origin.x: parent.width / 2
                origin.y: parent.height / 2
            }
            scale: initScanle
        }

        Text {
            id: text9
            x: 468
            y: 510
            width: 16
            height: 26
            color: "#ffffff"
            text: "9"
            //font.family: fontFamily
            elide: Text.ElideNone
            verticalAlignment: Text.AlignVCenter
            clip: false
            horizontalAlignment: Text.AlignHCenter
            lineHeight: 1
            opacity: initOpacity
            font.bold: true
            font.pixelSize: 26
            transform: Scale{
                origin.x: parent.width / 2
                origin.y: parent.height / 2
            }
            scale: initScanle
        }

}
