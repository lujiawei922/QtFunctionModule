#ifndef WEATHER_H
#define WEATHER_H

#include <QObject>
#include <QMap>
/**
 * @projectName: CHttp
 * @Description: 该类用于存放从json串中解析出来的天气数据,该函数只作用为Myjson类的私有成员不做它用，
 *               只有数据改变的时候会将数据通过信号函数
 * @Autor: lujiawei LJW@lierda.com
 * @date: 2019-07-15
 * @Version: 1.0.0
 * @update_autor
 * @update_time
**/
class Weather : public QObject
{
    Q_OBJECT
public:
    explicit Weather(QObject *parent = nullptr);
    void setWeather(QMap<QString,QString>& _baseinfo,QMap<QString,QString>& _pm_25,QList<QMap<QString,QString>>& _dayall);

signals:
    void sendWeather(QMap<QString,QString>& _baseinfo,QMap<QString,QString>& pm_25,QList<QMap<QString,QString>>& dayall);


public slots:

private:
    //包含province，city，wendu，qixiang，nowqixiang，fengli的基本信息
    QMap<QString,QString> baseinfo;
    //包含pm25的level（空气质量），pm25_tip，value（数值）等基本信息
    QMap<QString,QString> pm_25;
    /*包含day0-day5的五个map信息，每个map包含air_quality，baitianfengli，
     *baitianfengxiang，baitianqixiang，baitianwendu，date_day，richu，riluo，
     *wanshangfengli，wanshangfengxiang，wanshangqixiang，wanshangwendu基本信息
     */
    QList<QMap<QString,QString>> dayall;
};

#endif // WEATHER_H
