import QtQuick 2.0

Item {
    property int currentRpm: 0 // 实时的转速值
    property int currentSpeed: 0 // 实时的转速值
    property int angle: 270    // 每次旋转总的角度
    property int maxRpm: 9000  // 最大转速值
    property int rpmDurationTime: 800 //设置rpm动画时间
    property int speedDurationTime: 1000 //设置速度动画时间
    property int animationType: Easing.Linear

    RpmNumUpAndBright{
        id:rpmnum
        anchors.fill: parent
    }

    DynamicImageSelector{
        id: speedDynamicImageSelector
        anchors.fill: parent
        itemX: 1431
        itemY: 303
        Image {
            id: image
            x: 1552
            y: 424
            width: 72
            height: 30
            source: "qrc:/Image/Classical/Image/SpeedAndCapacity/Speed/km_h.png"
        }
    }

    DynamicImageSelector{
        id: rpmDynamicImageSelector
        anchors.fill: parent
        itemX: 162
        itemY: 303
    }

    Item {
            id: needle
            x: 312
            y: 32
            width: 16
            height: 325
            transformOrigin: Item.Bottom
            rotation: -135
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

    PropertyAnimation{
        id: speedAnimation
        target: speedDynamicImageSelector
        property: "currentValue"
        duration: speedDurationTime
        to:currentSpeed
    }

    ParallelAnimation{ //转速动画
            id : rpmAnimation

            RotationAnimation{ //指针转速动画
                target: needle
                duration: rpmDurationTime
                to: -135 + angle *( currentRpm / maxRpm )
                easing.type:  animationType
            }

            PropertyAnimation{ //数字转速动画
                target: rpmnum
                property: "currentValue"
                to: currentRpm
                duration: rpmDurationTime
                easing.type:  animationType
            }

    //        PropertyAnimation{ // 外环转速动画
    //            target: idTachArk
    //            property: "arcValue"       // "arcRadianEnd"
    //            to: currentRpm/1000         // 动态转速数值，  大小要缩放1000
    //            duration: rpmDurationTime
    //            easing.type:  animationType
    //        }

            PropertyAnimation{
                target: rpmDynamicImageSelector
                property: "currentValue"
                to: currentRpm
                duration: rpmDurationTime
                easing.type:  Easing.InQuad
            }
        }

}
