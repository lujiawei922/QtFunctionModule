#include "myjson.h"

MyJson* MyJson::js_instance = nullptr;
MyJson::Garbo MyJson::garbo;  //静态类对象类外声
QMutex MyJson::mutex ;

MyJson::MyJson(QObject *parent) : QObject(parent)
{
    ptr_weather = new  Weather(this);
}

MyJson *MyJson::getInstance()
{
    if (js_instance == nullptr)
    {
        mutex.lock();
        if(js_instance == nullptr)
        {
            //保证new时的原子操作，分两步
            MyJson* t_js_instance = new MyJson(nullptr);
            js_instance  = t_js_instance;
        }
        mutex.unlock();
    }
    return js_instance;
}

void MyJson::getreply(QNetworkReply *reply,int apiindex)
{
    //写操作时加写锁
    internalMutex.lockForWrite();
    QByteArray data = reply->readAll();

    qDebug()<<"hahahahahahahah"<<__LINE__;
    //接收到的数据不是json串另外处理
    if( Myenum::RequsetApi::GetLive == apiindex )
    {
        qDebug()<<"hahahahahahahah"<<__LINE__;
        QFile file("./cctv1live.m3u8");
        if(! file.open(QIODevice::WriteOnly) )
        {
              qDebug()<<file.errorString()<<__LINE__;
        }
        else
        {
            file.write(data);
            file.flush();
            file.close();
        }

    }
    else
    {
        json = QJsonDocument::fromJson(data, &jsonError);

        if (jsonError.error == QJsonParseError::NoError)
        {
            switch (apiindex)
            {
            case Myenum::RequsetApi::GetWeather:
                getWeahter(json);
                break;

            case Myenum::RequsetApi::GetMusic:
                getMusic(json);
                break;

            default:

                break;
            }

        }

    }


    QFile file("./cctv1live.m3u8");
    if(! file.open(QIODevice::ReadOnly) )
    {
          qDebug()<<file.errorString();
    }
    else
    {
        qDebug()<<file.readAll()<<__LINE__;
        file.close();
    }


    //解锁
    internalMutex.unlock();
}

void MyJson::getWeahter(QJsonDocument &json)
{
    QMap<QString,QString> baseinfo;
    QMap<QString,QString> pm_25;
    QMap<QString,QString> day;
    QList<QMap<QString,QString>> dayall;
    double t_number;

    baseinfo.insert("province","");
    baseinfo.insert("city","");
    baseinfo.insert("wendu","");
    baseinfo.insert("qixiang","");
    baseinfo.insert("nowqixiang","");
    baseinfo.insert("fengli","");

    pm_25.insert("level","");
    pm_25.insert("pm25_tip","");
    pm_25.insert("value","");

    day.insert("air_quality","");
    day.insert("baitianfengli","");
    day.insert("baitianfengxiang","");
    day.insert("baitianqixiang","");
    day.insert("baitianwendu","");
    day.insert("date_day","");
    day.insert("richu","");
    day.insert("riluo","");
    day.insert("wanshangfengli","");
    day.insert("wanshangfengxiang","");
    day.insert("wanshangqixiang","");
    day.insert("wanshangwendu","");


    if(json.isObject())
    {
        QJsonObject rootobj = json.object();
        QMap<QString,QString>::iterator it;
        //获取province，city，wendu，qixiang，nowqixiang，fengli的基本信息
        for(it = baseinfo.begin();it != baseinfo.end(); ++it)
        {
            if(rootobj.contains(it.key()))
            {
                QJsonValue value = rootobj.value(it.key());
                if (value.isString())
                {
                    it.value() = value.toString();
                }

                if (value.isDouble())
                {
                    t_number =value.toDouble();
                    it.value() = QString::number(t_number);
                }
            }
        }

        //获取pm_25的值
        if (rootobj.contains("pm_25"))
        {
            QJsonValue valueObj= rootobj.value("pm_25");

            if (valueObj.isObject())
            {
                 QJsonObject pmobj = valueObj.toObject();

                 QMap<QString,QString>::iterator it;

                 for(it = pm_25.begin();it != pm_25.end(); ++it)
                 {
                     if(pmobj.contains(it.key()))
                     {
                         QJsonValue value = pmobj.value(it.key());
                         if (value.isString())
                         {
                             it.value() = value.toString();
                         }

                         if (value.isDouble())
                         {
                             t_number =value.toDouble();
                             it.value() = QString::number(t_number);
                         }
                     }
                 }
            }
        }


        //获取dayall
        if (rootobj.contains("dayall"))
        {
            QJsonValue valueObj= rootobj.value("dayall");
            if (valueObj.isObject())
            {
                QJsonObject dayallobj = valueObj.toObject();

                QJsonObject::iterator it;
                for(it = dayallobj.begin(); it != dayallobj.end(); ++it)
                {
                    if(it->isObject())
                    {
                        QJsonObject  childobject = it->toObject();

                        QMap<QString,QString>::iterator it;
                        //获取day的基本信息
                        for(it = day.begin();it != day.end(); ++it)
                        {
                            if(childobject.contains(it.key()))
                            {
                                QJsonValue value = childobject.value(it.key());
                                if (value.isString())
                                {
                                    it.value() = value.toString();
                                }

                                if (value.isDouble())
                                {
                                    t_number =value.toDouble();
                                    it.value() = QString::number(t_number);
                                }
                            }
                        }

                        dayall.append(day);
                    }
                }

            }
        }


    }

    qDebug()<<baseinfo;
    qDebug()<<pm_25;
    qDebug()<<dayall;
}

void MyJson::getMusic(QJsonDocument &json)
{

}

void MyJson::getLive(QJsonDocument &json)
{

}
