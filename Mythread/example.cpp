#include "example.h"

Example::Example(QObject *parent) : QObject(parent)
{
    startThread();
}

Example::~Example()
{
    if(m_objThread)
    {
        m_objThread->quit();
    }
    m_objThread->wait();
}

void Example::startThread()
{
    if(m_objThread)
    {
        return;
    }
    m_objThread = new QThread();
    m_obj = new ThreadObject();
    m_obj->moveToThread(m_objThread);
    connect(m_objThread,&QThread::finished,m_objThread,&QObject::deleteLater);
    connect(m_objThread,&QThread::finished,m_obj,&QObject::deleteLater);
    connect(this,&Example::startwork1,m_obj,&ThreadObject::dowork1);
    connect(this,&Example::startwork2,m_obj,&ThreadObject::dowork2);

    m_objThread->start();
}
