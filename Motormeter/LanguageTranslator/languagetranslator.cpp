#include "languagetranslator.h"
#include <QDebug>

QMutex LanguageTranslator::mutex;
QAtomicPointer<LanguageTranslator> LanguageTranslator::instance = nullptr;

LanguageTranslator::LanguageTranslator(QObject *parent)
{
    Q_UNUSED(parent)
}


LanguageTranslator *LanguageTranslator::getInstance()
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
        instance.testAndSetOrdered(nullptr, new LanguageTranslator);//第二次检测。
    }

    return instance;

}

void LanguageTranslator::initLanguageTranslator(QGuiApplication &app, QQmlApplicationEngine &engine)
{
    m_app = &app;
    m_engine = &engine;
}

void LanguageTranslator::setLanguage(LanguageTranslator::LanguageType languageType)
{
    QString packetPath = packet_path;
    QDir dir(packetPath);
    if(!dir.exists()&&!dir.mkdir(packetPath)){
        qDebug()<<"mkdir false with file path-->" + packetPath;
    }
    QTranslator translator;
    bool flag = false;
    switch (languageType) {
    case  ZH_CN: flag = translator.load(packetPath + zh_CN_path); break;
    case  ZH_HK: flag = translator.load(packetPath + zh_HK_path); break;
    case  EN_US: flag = translator.load(packetPath + en_US_path); break;
    case  AR_AE: flag = translator.load(packetPath + ar_AE_path); break;
    case  AR_EG: flag = translator.load(packetPath + ar_EG_path); break;
    case  BE_BY: flag = translator.load(packetPath + be_BY_path); break;
    case  DA_DK: flag = translator.load(packetPath + da_DK_path); break;
    case  DE_AT: flag = translator.load(packetPath + de_AT_path); break;
    case  DE_DE: flag = translator.load(packetPath + de_DE_path); break;
    case  ES_ES: flag = translator.load(packetPath + es_ES_path); break;
    case  FR_FR: flag = translator.load(packetPath + fr_FR_path); break;
    case  IT_IT: flag = translator.load(packetPath + it_IT_path); break;
    case  JA_JA: flag = translator.load(packetPath + ja_JA_path); break;
    case  TH_TH: flag = translator.load(packetPath + th_TH_path); break;
    case  UK_UA: flag = translator.load(packetPath + uk_UA_path); break;
    }
    if(flag)
    {
        if(m_app==nullptr)
        {
            qDebug()<<"Please call initLanguageTranslator() function to set Envirment.";
        }
        if(m_app->installTranslator(&translator))
        {
            m_engine->retranslate();
        }else
        {
            qDebug()<<":Install Translator false,try again.";
        }
    }
    else
    {
        qDebug()<<packetPath + en_US_path;
        qDebug()<<": load language packet failed,language packet is exists in your path?";
    }

}


