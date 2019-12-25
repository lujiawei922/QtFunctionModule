import QtQuick 2.0

Item {
    property int currentCapacity: 0 //当前功耗值
        property int capacityType: Easing.Linear //功耗动画曲线速率
        property int capacityDurationTime: 500 //功耗动画时间
        property int angle: 120    // 功率指针每次旋转总的角度
        property int maxCapacity: 8000  // 功率指针最大值

    // 数字高亮显示
    NumUpAndBright{//功率数字提示
        id: capacityNum
        anchors.fill: parent
    }

    EF{//EF显示
        anchors.fill: parent
    }

    Item {//功率指针提示
           id: capacityNeedle
           x: 1586
           y: 32
           width: 16
           height: 325
           transformOrigin: Item.Bottom
           rotation: -120
           Image {
               x: 0
               y: 8
               width: 16
               height: 200
               fillMode: Image.TileHorizontally
               source: "qrc:/Image/Classical/Image/SpeedAndCapacity/needle.png"
           }
           transform: Rotation{
               origin.x: 10
               origin.y: 10
           }
       }

    ParallelAnimation{
        id: capacityAnimation
        PropertyAnimation{//功率数字动画
            target: capacityNum
            property: "currentValue"
            duration: capacityDurationTime
            to: currentCapacity
            easing.type: capacityType
        }
        RotationAnimation{//功率指针动画
            target: capacityNeedle
            duration: capacityDurationTime
            to: -120 + angle *( currentCapacity / maxCapacity )
            easing.type: capacityType
        }
    }

}
