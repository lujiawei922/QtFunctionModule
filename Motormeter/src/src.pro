QT += quick
CONFIG += c++11
# 允许大资源文件
CONFIG += resources_big

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp

RESOURCES += qml.qrc \
    font.qrc \
    image.qrc

DISTFILES += \
    ../LanguagePacket/en_US.qm \
    ../LanguagePacket/zh_CN.qm

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

include(App/app.pri)


# 连接到logger库
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../logger/release/ -llogger
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../logger/debug/ -llogger
else:unix: LIBS += -L$$OUT_PWD/../logger/ -llogger

INCLUDEPATH += $$PWD/../logger
DEPENDPATH += $$PWD/../logger

# 连接到LanguageTranslator
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../LanguageTranslator/release/ -lLanguageTranslator
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../LanguageTranslator/debug/ -lLanguageTranslator
else:unix: LIBS += -L$$OUT_PWD/../LanguageTranslator/ -lLanguageTranslator

INCLUDEPATH += $$PWD/../LanguageTranslator
DEPENDPATH += $$PWD/../LanguageTranslator

# 连接到本地设置库
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../ProcessIni/release/ -lProcessIni
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../ProcessIni/debug/ -lProcessIni
else:unix: LIBS += -L$$OUT_PWD/../ProcessIni/ -lProcessIni

INCLUDEPATH += $$PWD/../ProcessIni
DEPENDPATH += $$PWD/../ProcessIni
