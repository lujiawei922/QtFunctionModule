#ifndef EXAMPLE_H
#define EXAMPLE_H

#include <QObject>
#include <QThread>
#include "threadobject.h"

class Example : public QObject
{
    Q_OBJECT
public:
    explicit Example(QObject *parent = nullptr);
    ~Example();

signals:
    void startwork1(QString &parameter);
    void startwork2(QString &parameter);

public slots:

private:
    void startThread();
private:
    ThreadObject* m_obj;
    QThread* m_objThread;
};

#endif // EXAMPLE_H
