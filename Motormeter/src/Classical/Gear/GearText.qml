import QtQuick 2.0

Item {
    property string fontFamily: "STXIHEI"
    property int itemX: 935
    property int itemY: 645
    property int fontSize: 60

    property var gears: [gearP,gearR,gearN,gearD]

    Text {
        id: gearP
        x: itemX
        y: itemY
        color: "#ffffff"
        text: "P"
        //font.family: fontFamily
        font.bold: true
        visible: true
        font.pixelSize: fontSize
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
    }

    Text {
        id: gearR
        x: itemX
        y: itemY
        color: "#ffffff"
        text: "R"
        //font.family: fontFamily
        font.bold: true
        visible: false
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: fontSize
    }

    Text {
        id: gearN
        x: itemX
        y: itemY
        color: "#ffffff"
        text: "N"
        //font.family: fontFamily
        font.bold: true
        visible: false
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: fontSize
    }

    Text {
        id: gearD
        x: itemX
        y: itemY
        color: "#ffffff"
        text: "D"
        //font.family: fontFamily
        font.bold: true
        visible: false
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: fontSize
    }
}
