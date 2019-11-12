## 关于输入法插件编译说明
1. 先编译googlepinyin源码；
2. 把编译好的库文件libgooglepinyin.a放到plugin/googlepinyin目录下；
3. 再编译plugin源码，把编译后的库文件放到执行文件所在目录下的platforminputcontexts文件夹下；
4. 复制plugin目录下的dict目录到执行文件所在目录下；


## 关于板子Qt坐标系的问题
可以通过配置配置QT_QPA_EVDEV_TOUCHSCREEN_PARAMETERS的环境变量来偏转坐标系
export QT_QPA_EVDEV_TOUCHSCREEN_PARAMETERS=/deinput/event2:rotate=270

## 关于板子中文字体
可以将font下的字体库放入到板子中的字体库路径当中
