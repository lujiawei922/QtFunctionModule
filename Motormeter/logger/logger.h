#ifndef LOGGER_H
#define LOGGER_H

#include "logger_global.h"
#include <QMutex>
#include <QObject>
class LOGGERSHARED_EXPORT Logger:public QObject
{
    Q_OBJECT
public:
    Logger();
    /**
     * @brief myMessageOutput 修改默认打debug输出
     * @param type  输出类型
     * @param context 上下文环境
     * @param msg   输出信息
     */
    Q_INVOKABLE static void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg);
    Q_INVOKABLE static void logOn();
    Q_INVOKABLE static void logOff();
private:
    static bool m_logSwitch;
};

#endif // LOGGER_H
