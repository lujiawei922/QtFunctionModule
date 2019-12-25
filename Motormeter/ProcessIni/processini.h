#ifndef PROCESSINI_H
#define PROCESSINI_H

#include "processini_global.h"
#include <QSettings>
#include <QVariant>
#include <QByteArray>
#include <QCryptographicHash>
const QString IniFilePath = "./config.ini";

/**
 * @ClassName: ProcessIni
 * @Description: 系统配置信息保存
 * @Autor: zhanghao kinderzhang@foxmail.com
 * @date: 2018-09-25 16:48:00
 * @Version: 1.0.0
 * @update_autor
 * @update_time
**/
class PROCESSINISHARED_EXPORT ProcessIni
{

    enum EncryptionType{
        Md4,
        Md5,
        Sha1,
        Sha256,
        Sha512,
        Sha3_256,
        Sha3_512,
        Keccak_256,
        Keccak_512,
    };

public:
    /**
     * @MethodName: writeIni
     * @ClassName: ProcessIni
     * @Description: 写入配置信息
     * @Version: 1.0.0
     * @update_autor
     * @update_time
     * @Parma: [QString] content 结构树名称
     * @Parma: [QString] key 键名
     * @Parma: [QVariant] data 键值
     * @Return: [bool] 写入状态
    **/
    Q_INVOKABLE static bool writeIni(QString content,QString key,QVariant data);
    /**
     * @MethodName: readIni
     * @ClassName: ProcessIni
     * @Description: 读取配置项信息
     * @Version: 1.0.0
     * @update_autor
     * @update_time
     * @Parma: [QString] content 结构树名称
     * @Parma: [QString] key 键名
     * @Return: [QVariant] 键值
    **/
    Q_INVOKABLE static QVariant readIni(QString content,QString key);
    /**
     * @MethodName: getIniFilePath
     * @ClassName: ProcessIni
     * @Description: 返回配置文件路径
     * @Version: 1.0.0
     * @update_autor
     * @update_time
     * @Return: [QString] 配置文件路径
    **/
    Q_INVOKABLE static QString getIniFilePath();

    /**
     * @Title: encryptionData
     * @Class: ProcessIni
     * @Description: 对输入的数据进行加密
     * @update_author
     * @update_time
     * @version V1.0
     * @param [QByteArray] data 需要加密的数据
     * @param [EncryptionType] type 加密方式
     * @return [QString] 加密后的文本
    */
    Q_INVOKABLE static QString encryptionData(const QByteArray &data,EncryptionType type);

    /**
     * @Title: encryptionData
     * @Class: ProcessIni
     * @Description: 对输入的数据进行加密
     * @update_author
     * @update_time
     * @version V1.0
     * @param [QString] data 需要加密的数据
     * @param [EncryptionType] type 加密方式
     * @return [QString] 加密后的文本
    */
    Q_INVOKABLE static QString encryptionData(const QString &data,EncryptionType type);


};

#endif // PROCESSINI_H
