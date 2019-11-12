QT          += gui-private widgets

TEMPLATE    = lib
TARGET      = tgtsmlInputContextPlugin

LIBS        += -L$$PWD/googlepinyin/ -lgooglepinyin
INCLUDEPATH += $$PWD/googlepinyin

HEADERS     += \
            tgtsmlplatforminputcontextplugin.h \
            tgtsmlplatforminputcontext.h \
            keyboardform.h

SOURCES     += \
            tgtsmlplatforminputcontextplugin.cpp \
            tgtsmlplatforminputcontext.cpp \
            keyboardform.cpp

RESOURCES   += \
            res.qrc


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../googlepinyin/release/ -lgooglepinyin
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../googlepinyin/debug/ -lgooglepinyin
else:unix: LIBS += -L$$OUT_PWD/../googlepinyin/ -lgooglepinyin

INCLUDEPATH += $$PWD/../googlepinyin
DEPENDPATH += $$PWD/../googlepinyin

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../googlepinyin/release/libgooglepinyin.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../googlepinyin/debug/libgooglepinyin.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../googlepinyin/release/googlepinyin.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../googlepinyin/debug/googlepinyin.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../googlepinyin/libgooglepinyin.a
