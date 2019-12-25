import QtQuick 2.0

Item {
    property int itemX: 0
    property int itemY: 0
    property int itemWidth: 200
    property int itemHeight: 20
    property int currentValue: 0 //设置当前高亮显示项
    property string textColor: "white" //设置字体的颜色
    property double initOpacity: 0.5 //菜单指示图标默认的透明度
    property var texts: [navigationText,musicText,phoneText,setteingText,carWaringText]
    property int duration: itemWidth / texts.length

    onCurrentValueChanged: {
        for(var index =0;index < texts.length;index++){
            texts[index].opacity = initOpacity
        }
        texts[currentValue].opacity = 1
    }

    Text {
            id: navigationText
            font.family: "FontAwesome"
            font.pixelSize: itemHeight
            color: textColor
            text: "\uf124"
            opacity: 1
            x: itemX + duration / 2
            y: itemY
        }
        Text {
            id: musicText
            font.family: "FontAwesome"
            font.pixelSize: itemHeight
            color: textColor
            text: "\uf001"
            opacity: initOpacity
            x: navigationText.x + duration
            y: itemY
        }
        Text {
            id: phoneText
            font.family: "FontAwesome"
            font.pixelSize: itemHeight
            color: textColor
            text: "\uf095"
            opacity: initOpacity
            x:musicText.x + duration
            y: itemY
        }
        Text {
            id: setteingText
            font.family: "FontAwesome"
            font.pixelSize: itemHeight
            color: textColor
            text: "\uf085"
            opacity: initOpacity
            x:phoneText.x + duration
            y: itemY
        }
        Text {
            id: carWaringText
            font.family: "FontAwesome"
            font.pixelSize: itemHeight
            color: textColor
            text: "\uf1b9"
            opacity: initOpacity
            x:setteingText.x + duration
            y: itemY
        }
}
