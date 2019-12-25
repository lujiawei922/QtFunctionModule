import QtQuick 2.0
import QtQuick.Controls 2.0
import QtGraphicalEffects 1.0
import QtMultimedia 5.8

Item {
      property bool asynch: false //是否异步加载图像数据
      property string path: "./navi.mp4"

      function play(){
          mediaplayer.play()
      }
      function pause(){
          mediaplayer.pause()
      }

      Image {
          id: mask
          width: parent.width
          height: parent.height
          source: "qrc:/Image/Common/Mask/EdgeMask2.png"
          smooth: true
          visible: false
      }
      OpacityMask{
          anchors.fill: parent
          source: output
          maskSource: mask
      }
      MediaPlayer {
          id: mediaplayer
          source: path
      }

      VideoOutput {
          id: output
          source: mediaplayer
          visible: false
      }
}
