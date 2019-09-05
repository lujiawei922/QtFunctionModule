/*!
 * \file websoc.h
 * \brief 一个websocket的接受类，用于websocket的接受
 * \date  2019-09-03
 * \author ljw <ljw@lierda.com>
 */
#ifndef WEBSOC_H
#define WEBSOC_H

#include <QObject>
#include <QWebSocket>
#include <QString>
#include <QTimer>
#include "cmaskgenerator.h"

const QString wsaddress = "***************************";

class WebSoc : public QObject
{
    Q_OBJECT
public:
    explicit WebSoc(QObject *parent = nullptr);
    ~WebSoc();

signals:
    void sendpath(QString path);

public slots:
    void createDataRecvWS();    /*-<创建websocket连接 */

private:
    void reconnect();           /*-<周期重连函数 */

    QWebSocket *dataRecvWS;     /*-<websocket类 */
    CMaskGenerator *m_mask;
    bool connectStatus;         /*-<websocket连接状态，连接成功：true；断开：false */
    QTimer *m_timer;            /*-<周期重连Timer */


private slots:
    void onConnected();                 /*-<socket建立成功后，触发该函数 */
    void onTextReceived(QByteArray msg);   /*-<收到Sev端的数据时，触发该函数 */
    void onDisConnected();
public slots:
    void onTextSend(QString path);

public slots:
};

#endif // WEBSOC_H
