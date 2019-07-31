#ifndef THREADOBJECT_H
#define THREADOBJECT_H

#include <QObject>
#include <QMutex>
/**
 * @ClassName: ThreadObject:线程功能实现的实体
 * @Description:
 * @Autor: lujiawei 635981519@qq.com
 * @date: 2019-07-29
 * @Version: 1.0.0
 * @update_autor
 * @update_time
**/

class ThreadObject : public QObject
{
    Q_OBJECT
public:
    explicit ThreadObject(QObject *parent = nullptr);

signals:
    void resultReady(const QString &result);

public slots:
    /**
     * @brief dowork1   ：主要的实现过程
     * @param parameter：需要传入的参数
     */
    void dowork1(const QString &parameter);
    void dowork2(const QString &parameter);

    /**
     * @brief mymutex:私有锁，用于全局变量的读写保护，可以使用它的便利类QMutexLocker
     */
    QMutex mymutex;
};

#endif // THREADOBJECT_H
