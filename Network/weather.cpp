#include "weather.h"

Weather::Weather(QObject *parent) : QObject(parent)
{

}

void Weather::setWeather(QMap<QString,QString>& _baseinfo,QMap<QString, QString>& _pm_25, QList<QMap<QString, QString> >& _dayall)
{
    baseinfo =_baseinfo;
    pm_25 = _pm_25;
    dayall = _dayall;

    emit sendWeather(_baseinfo,pm_25,dayall);
}

