#ifndef MESSAGING_H
#define MESSAGING_H

#include <QObject>
#include <QDebug>
#include <QMutex>
#include <QAtomicPointer>
#include <QReadWriteLock>

class Singleton : public QObject
{
    Q_OBJECT
public:
    static Singleton *getInstance();
    ~Singleton();
signals:
private:
       class Garbo //设置为私有防止外界访问
       {
           public:
               ~Garbo()//实际去析构new的单例对象
               {
                   if(Singleton::instance != nullptr)
                   {
                       qDebug() << "delete m_instance" ;
                       delete Singleton::instance;
                       Singleton::instance = nullptr;
                   }
               }
       };
private:
    explicit Singleton(QObject *parent = nullptr);
    Singleton(const Singleton &);//禁止拷贝构造函数。
    Singleton & operator=(const Singleton &);//禁止赋值拷贝函数。

    QReadWriteLock internalMutex;//函数使用的读写锁。
    static QMutex mutex;//实例互斥锁。

    static Garbo garbo;         //静态私有的嵌套类对象,防止被外界访问
    static QAtomicPointer<Singleton> instance;/*!<使用原子指针,默认初始化为0。*/


};

#endif // MESSAGING_H
