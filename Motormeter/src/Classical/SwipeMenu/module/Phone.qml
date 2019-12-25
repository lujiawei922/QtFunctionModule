import QtQuick 2.0

Item {
    property int    phoneBookShowNumbers: 3         // 一页展示几条纪录  需要设置
    property int    phoneBookHeightPerItem: 110     // 单条纪录的大小-高度  根据需求设置
    property int    phoneBookWidthPerItem: 450      // 单条纪录的大小-宽度  根据需求设置
    property int    phoneBookHeight: phoneBookHeightPerItem*phoneBookShowNumbers    // 滚动框 高，根据个数自动计算，无需设置
    property int    phoneBookWidth: phoneBookWidthPerItem                           // 滚动框 高，一般与单条记录宽度相等，可根据需求设置
    property int    highlightBeginPos: (phoneBookHeight-phoneBookHeightPerItem)/2    // 高亮区域 居中设置 起始位置，自动计算，无需设置
    property int    highlightEndPos: highlightBeginPos+phoneBookHeightPerItem        // 高亮区域 居中设置 截止位置自动计算，无需设置
    property int    itemXPos: (parent.width - phoneBookWidth)/2             // 电话记录滚动框 x坐标 自动居中无需设置
    property int    itemYPos: (parent.height - phoneBookHeight)/2//+100      // 电话记录滚动框 y坐标 自动居中无需设置
    property string textColor: "white"      // 设置字体的颜色
    property string fontFamily: "STXIHEI"   // 设置字体的样式
    property bool   transboundary: false    // 按键操作是否越界，不需设置
    property int    boundaryTopY: itemYPos     // 按键上边界位置，不需设置
    property int    boundaryBottomY: itemYPos + (phoneBookShowNumbers-1)*phoneBookHeightPerItem     // 按键下边界位置，不需设置
    property int    currentValue: 0         // 选中项目的索引，app传入，不需设置
}
