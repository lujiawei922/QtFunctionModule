#include "singleton.h"

//静态成员变量初始化。
QMutex Singleton::mutex;
QAtomicPointer<Singleton> Singleton::instance = nullptr;

Singleton *Singleton::getInstance()
{

#ifndef Q_ATOMIC_POINTER_TEST_AND_SET_IS_ALWAYS_NATIVE
        if(!QAtomicPointer::isTestAndSetNative())//运行时检测
            qDebug() << "Error: TestAndSetNative not supported!";
#endif

        //使用双重检测。
        /*! testAndSetOrders操作保证在原子操作前和后的的内存访问
         * 不会被重新排序。
         */
        if(instance.testAndSetOrdered(nullptr, nullptr))//第一次检测
        {
            QMutexLocker locker(&mutex);//加互斥锁。

            instance.testAndSetOrdered(nullptr, new Singleton);//第二次检测。
        }

        return instance;

}

Singleton::~Singleton()
{

}

Singleton::Singleton(QObject *parent) : QObject(parent)
{

}
