#ifndef LANGUAGETRANSLATOR_H
#define LANGUAGETRANSLATOR_H

#include "languagetranslator_global.h"
#include <QObject>
#include <QTranslator>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDir>
#include <QDebug>
#include <QMutex>
#include <QReadWriteLock>

// 将最后生成翻译好的qm文件放在运行目录下的LanguagePacket文件夹中
const QString packet_path = "../LanguagePacket";

const QString zh_CN_path = "zh_CN.qm";
const QString zh_HK_path = "zh_HK.qm";
const QString en_US_path = "en_US.qm";
const QString ar_AE_path = "ar_AE.qm";
const QString ar_EG_path = "ar_EG.qm";
const QString be_BY_path = "be_BY.qm";
const QString da_DK_path = "da_DK.qm";
const QString de_AT_path = "de_AT.qm";
const QString de_DE_path = "de_DE.qm";
const QString es_ES_path = "es_ES.qm";
const QString fr_FR_path = "fr_FR.qm";
const QString it_IT_path = "it_IT.qm";
const QString ja_JA_path = "ja_JA.qm";
const QString th_TH_path = "th_TH.qm";
const QString uk_UA_path = "uk_UA.qm";


class LANGUAGETRANSLATORSHARED_EXPORT LanguageTranslator: public QObject
{
    Q_OBJECT
public:
    Q_ENUMS(LanguageType)
    enum LanguageType{
        ZH_CN,//中文(中国)
        ZH_HK,//中文(台湾)
        EN_US,//英文(美国)
        AR_AE,//阿拉伯文(阿拉伯联合酋长国)
        AR_EG,//阿拉伯文(埃及)
        BE_BY,//白俄罗斯文(白俄罗斯)
        DA_DK,//丹麦文(丹麦)
        DE_AT,//德文(奥地利)
        DE_DE,//德文(德国)
        ES_ES,//西班牙文(西班牙)
        FR_FR,//法文(法国)
        IT_IT,//意大利文(意大利)
        JA_JA,//日文(日本)
        TH_TH,//泰文(泰国)
        UK_UA //乌克兰文(乌克兰)
    };
    /**
     * @brief getInstance 获取翻译类打单例
     * @return  返回唯一单例
     */
    static LanguageTranslator * getInstance();
    /**
      * @brief initLanguageTranslator 配置应用程序app与qml的engine
      * @param app      应用程序app的引用
      * @param engine   qml的engine的引用
      */
    Q_INVOKABLE void initLanguageTranslator(QGuiApplication& app, QQmlApplicationEngine &engine);
    /**
     * @brief setLanguage   设置语言包
     * @param languageType  对应的国家语言包
     */
    Q_INVOKABLE void setLanguage(LanguageTranslator::LanguageType languageType);

private:
       class Garbo //设置为私有防止外界访问
       {
           public:
               ~Garbo()//实际去析构new的单例对象
               {
                   if(LanguageTranslator::instance != nullptr)
                   {
                       qDebug() << "delete m_instance" ;
                       delete LanguageTranslator::instance;
                       LanguageTranslator::instance = nullptr;
                   }
               }
       };

private:
    explicit LanguageTranslator(QObject *parent = nullptr);
    LanguageTranslator(const LanguageTranslator &);//禁止拷贝构造函数。
    LanguageTranslator & operator=(const LanguageTranslator &);//禁止赋值拷贝函数。

    static Garbo garbo;
    static QAtomicPointer<LanguageTranslator> instance;/*!<使用原子指针,默认初始化为0。*/

    QReadWriteLock internalMutex;//函数使用的读写锁。
    static QMutex mutex;//实例互斥锁。

    QGuiApplication *m_app;
    QQmlApplicationEngine *m_engine;
};

#endif // LANGUAGETRANSLATOR_H
