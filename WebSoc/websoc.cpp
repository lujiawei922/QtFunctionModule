/*!
 * \file websoc.cpp
 * \brief
 * \date  2019-09-03
 * \author ljw <ljw@lierda.com>
 */
#include "websoc.h"
#include <QFile>
#include <QDataStream>
#include <QFileInfo>

WebSoc::WebSoc(QObject *parent) : QObject(parent)
{
    dataRecvWS = Q_NULLPTR;
    connectStatus = false;
    m_timer = new QTimer(this);
}

WebSoc::~WebSoc()
{

}

void WebSoc::createDataRecvWS()
{
    if(dataRecvWS == Q_NULLPTR)
    {
        m_mask = new CMaskGenerator();
        dataRecvWS = new QWebSocket(QString(), QWebSocketProtocol::VersionLatest, this);
        dataRecvWS->setMaskGenerator(m_mask);
        qDebug()<<"create websocket!";
        connect(dataRecvWS,&QWebSocket::disconnected,this,&WebSoc::onDisConnected,Qt::AutoConnection);
        connect(dataRecvWS,&QWebSocket::binaryMessageReceived,this,&WebSoc::onTextReceived,Qt::AutoConnection);
        connect(dataRecvWS,&QWebSocket::connected,this,&WebSoc::onConnected,Qt::AutoConnection);
        connect(m_timer,&QTimer::timeout,this,&WebSoc::reconnect,Qt::AutoConnection);
        connect(this,&WebSoc::sendpath,this,&WebSoc::onTextSend,Qt::AutoConnection);
        dataRecvWS->open(QUrl(wsaddress));
    }
}

void WebSoc::reconnect()
{
    qDebug()<<"try to reconnect!";
    dataRecvWS->abort();
    dataRecvWS->open(QUrl(wsaddress));
}

void WebSoc::onConnected()
{
    qDebug()<<"DataReveive websocket is already connect!";
    connectStatus = true;
    m_timer->stop();
    qDebug()<<"Address："<<dataRecvWS->peerAddress();
    emit sendpath("E:/Myshare/build-CHttp-Desktop_Qt_5_11_2_MinGW_32bit-Debug/src/debug/test.pcm");
}

void WebSoc::onTextReceived(QByteArray msg)
{
    qDebug()<<"----------------data-----------------";
    qDebug()<<msg;
}

void WebSoc::onDisConnected()
{
    qDebug()<<"DataReceive websocket is disconnected!!!";
    connectStatus = false;
    qDebug()<<dataRecvWS->errorString();
    qDebug()<<dataRecvWS->closeReason();
    //m_timer->start(3000);/*-<当连接失败时，触发重连计时器，设置计数周期为3秒 */
}

void WebSoc::onTextSend(QString path)
{
    QFileInfo info(path);
    QString file_name = info.fileName();
    //dataRecvWS->sendTextMessage("f:" + file_name);

    QFile file(path);
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug()<< file.errorString();
        return;
    }
    else
    {
        qDebug()<<"open successed!";
    }

//    QDataStream in(&file);
//    in.setVersion(QDataStream::Qt_5_10);
//    in >> s;
    QByteArray byte = file.readAll();
    qDebug()<<"number is"<<dataRecvWS->sendBinaryMessage(byte);
    file.close();
}
