import QtQuick 2.0

Item {
    id: item
    property int currentValue: 0      // 需要设置的值
    property int itemX: 0    // 设置显示的X位置
    property int itemY: 0    // 设置显示的Y位置
    property int imgWidth: 78  // 设置图片的宽度
    property int imgHeight: 115// 设置图片的高度
    property var pictures: [// 设置显示的图片
            "qrc:/Image/Classical/Image/SpeedAndCapacity/Speed/0.png",
            "qrc:/Image/Classical/Image/SpeedAndCapacity/Speed/1.png",
            "qrc:/Image/Classical/Image/SpeedAndCapacity/Speed/2.png",
            "qrc:/Image/Classical/Image/SpeedAndCapacity/Speed/3.png",
            "qrc:/Image/Classical/Image/SpeedAndCapacity/Speed/4.png",
            "qrc:/Image/Classical/Image/SpeedAndCapacity/Speed/5.png",
            "qrc:/Image/Classical/Image/SpeedAndCapacity/Speed/6.png",
            "qrc:/Image/Classical/Image/SpeedAndCapacity/Speed/7.png",
            "qrc:/Image/Classical/Image/SpeedAndCapacity/Speed/8.png",
            "qrc:/Image/Classical/Image/SpeedAndCapacity/Speed/9.png",
        ]
    property var value: [unit,decade,hundreds,kilobit]

    function updateEffect(){
            // 清除之前的信息
            for(var j = 0; j < value.length ; j++)
            {
                value[j].source = ""
            }

            var speed = currentValue.toString()
            var baseX = itemX + (value.length - speed.length) * imgWidth / 2
            for(var i = 0; i < speed.length ; i++){
                value[i].source = pictures[speed[i ]]
                value[i].x = baseX + imgWidth * i
            }
        }

    onCurrentValueChanged: {
        updateEffect()
    }

    Component.onCompleted: {
        updateEffect()
    }

    Item{
        anchors.fill: parent
        Image {
            id: kilobit
            y:  itemY
            width: imgWidth
            height: imgHeight
        }
        Image {
            id: hundreds
            y:  itemY
            width: imgWidth
            height: imgHeight
        }
        Image {
            id: decade
            y:  itemY
            width: imgWidth
            height: imgHeight
        }
        Image {
            id: unit
            y:  itemY
            width: imgWidth
            height: imgHeight
        }
    }


}
