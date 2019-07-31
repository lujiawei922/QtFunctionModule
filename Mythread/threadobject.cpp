#include "threadobject.h"

ThreadObject::ThreadObject(QObject *parent) : QObject(parent)
{

}

void ThreadObject::dowork1(const QString &parameter)
{
    /*
     *具体功能
     */
    emit resultReady(parameter);
}

void ThreadObject::dowork2(const QString &parameter)
{
    /*
     *具体功能
     */
    emit resultReady(parameter);
}

