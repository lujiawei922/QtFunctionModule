#ifndef MYJSON_H
#define MYJSON_H
#include <QJsonDocument>

#include <QObject>
#include <QMutex>
#include <QDebug>
#include <QNetworkReply>
#include <QReadWriteLock>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QIODevice>
#include "weather.h"
#include "myenum.h"

/**
 * @projectName: CHttp
 * @Description: 该类用于解析json字符串，并将解析的数据放入自身的类中，
 *               相当于一个全局的缓存区，是一个单例类
 * @Autor: lujiawei LJW@lierda.com
 * @date: 2019-07-15
 * @Version: 1.0.0
 * @update_autor
 * @update_time
**/
class MyJson : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief getInstance :获取单例类的操作指针
     * @return
     */
    static MyJson *getInstance();

    /**
     * @brief mutex ：单例类锁，防止多线程操作时产生的错误
     */
    static QMutex mutex;

signals:

public slots:
    void getreply(QNetworkReply * reply,int apiindex);

private:
    /*单例类不能在本身的析构函数中析构，用于析构单例类*/
    class Garbo
    {
    public:
        ~Garbo()
        {
            if(MyJson::js_instance != nullptr)
            {
                qDebug() << "delete js_instance" ;
                delete MyJson::js_instance;
                MyJson::js_instance = nullptr;
            }
        }

    };

    explicit MyJson(QObject *parent = nullptr);
    //单例唯一实例
    static MyJson* js_instance;
    //静态私有的嵌套类对象,防止被外界访问
    static Garbo garbo;
    //Qt5新类,用于处理JSON解析的报错
    QJsonParseError jsonError;
    //用于发送或者接收json文档
    QJsonDocument json ;
    //函数使用的读写锁
    QReadWriteLock internalMutex;
    //天气类
    Weather* ptr_weather;

    /**
     * @brief getWeahter :解析天气的json字符串
     * @param json :从服务器接收的关于天气的json数据
     */
    void getWeahter(QJsonDocument& json);

    /**
     * @brief getMusic :解析音乐的json字符串
     * @param json :从服务器接收的关于音乐的json数据
     */
    void getMusic(QJsonDocument& json);

    /**
     * @brief getLive :解析live的数据
     * @param json ::从服务器接收的关于live的json数据
     */
    void getLive(QJsonDocument& json);

};

#endif // MYJSON_H
