import QtQuick 2.0

Item {
    property int tempratureX: 626 //温度X位置
    property int tempratureY: 54  //湿度Y位置
    property int timeX: 960 //时间X位置
    property int timeY: 50  //时间Y位置
    //property string fontFamily: "STXIHEI"
    property int tripAX: 1209
    property int tripAY: 54
    property int odoX: 674
    property int odoY: 655
    property string hour: "00"
    property string minutes: "00"

    Text {
        id: temprature
        x: tempratureX
        y: tempratureY
        width: 30
        height: 30
        color: "#ffffff"
        text: "00"
        //font.family: fontFamily
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        fontSizeMode: Text.FixedSize
        font.bold: true
        font.pixelSize: 30

        Image {
            x: 36
            y: 2
            width: 25
            height: 22
            source: "qrc:/Image/Classical/Image/SpeedAndCapacity/C.png"
        }
    }

    Text {
        id: time
        x: timeX - width / 2
        y: timeY
        width: 75
        height: 30
        color: "#ffffff"
        text: "00:00"
        //font.family: fontFamily
        font.bold: true
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 30
    }

    Text {
        id: tripA
        x: tripAX
        y: tripAY
        width: 75
        height: 30
        color: "#ffffff"
        text: "0km"
        //font.family: fontFamily
        font.bold: true
        horizontalAlignment: Text.AlignRight
        font.pixelSize: 30
    }

    Text {
        id: textOdo
        x: odoX
        y: odoY
        width: 159
        height: 37
        color: "#ffffff"
        text: "0km"
        //font.family: fontFamily
        horizontalAlignment: Text.AlignLeft
        font.pixelSize: 45
        font.bold: true
        Text {
            x: -125
            y: -5
            width: 94
            height: 50
            color: "#ffffff"
            text: "ODO"
            //font.family: fontFamily
            opacity: 0.85
            font.pixelSize: 50
        }
    }
}
