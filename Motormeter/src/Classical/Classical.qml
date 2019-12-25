import QtQuick 2.0
import "../Classical/Sysbolwarning"
import "../Classical/SpeedAndRpm"
import "../Classical/Capacity"
import "../Classical/Gear"
import "../Classical/SwipeMenu"
import "../Common/"


Item {
    Image {
        id: background
        source: "qrc:/Image/Classical/Image/background.png"
    }

    // 符号灯组件
   Sysbolwarning{
        anchors.fill: parent
    }

   // 速度和转速组件
   Rpm{
       anchors.fill: parent
   }

   // 电耗和EF组件
   Capacity{
       anchors.fill: parent
   }

   // 基础信息组件
   BaseInfo{
       anchors.fill: parent
   }

   //档位信息组件
   GearText{
   }


   //行车菜单信息组件
   SwipeMenu{
   }
}
