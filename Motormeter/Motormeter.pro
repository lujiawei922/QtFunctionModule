TEMPLATE = subdirs

SUBDIRS += \
    ProcessIni \
    LanguageTranslator \
    logger \
    src
CONFIG +=ordered

# 在release版本下输出log信息
DEFINES += QT_MESSAGELOGCONTEXT
