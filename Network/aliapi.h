#ifndef ALIAPI_H
#define ALIAPI_H

#include <QObject>
#include <QByteArray>
#include <QString>
#include <QMessageAuthenticationCode>
#include <QNetworkAccessManager>
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUuid>
#include <QMap>
#include <QDebug>
#include <QEventLoop>
#include "myjson.h"


//AppKey
const QString AppKey = "203722337";
//AppSecret
const QString AppSecret = "62r30qu7zlxq3h3vbmww4blml3g9bv5d";
//API接口
const QStringList ReqApi({"/weather/v1/getWeather","/live/v1/cctv1","/music/v1/search"});
//请求方法
const QString HTTPMethod = "GET";
//发送内容类型
const QString Content_Type = "application/x-www-form-urlencoded";
//接收内容类型
const QString Accept = "application/json";
//const QString Accept = "application/octet-stream";
//Host
const QString HOST = "api.zhipinglife.cn";
//加密方法
const QString X_Ca_SignatureMethod = "HmacSHA256";

/**
 * @projectName: CHttp
 * @Description:用于阿里云API接口的Htpp连接和签名
 * @Autor: lujiawei LJW@lierda.com
 * @date: 2019-07-09
 * @Version: 1.0.0
 * @update_autor
 * @update_time
**/

class AliApi : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief AliApi  ：构造函数
     * @param apiindex ：对应着使用哪一个API功能
     * @param querypam：要传入的QueryParamemter
     * @param parent
     */
    explicit AliApi(int apiindex,QMap<QString,QString> &querypam,QObject *parent = nullptr);

    /*析构函数，当申请动态内存的时候请记得在这里释放*/

    /**
     * @brief CopyBodyStream :该函数接口为外部给body赋值使用
     * @param t_bodystream : body的字节流
     */
    void CopyBodyStream(const QByteArray & t_bodystream);

    /**
     * @brief NetworkRequest:建立网络请求
     */
    void NetworkRequest();

private:
    /**
     * @brief HeaderInit :对请求头做初始化
     */
    void HeaderInit();

    /**
     * @brief getMD5 ：对Body部分进行MD5加密
     * @param bytes_ ：Body部分
     * @return
     */
    QByteArray GetMD5(QByteArray bytes_);

    /**
     * @brief HMACSha256：对
     * @param key       ：由阿里云提供的密钥
     * @param baseString：需要加密的字符串
     * @return
     */
    void HMACSha256(QByteArray key, QByteArray baseString);

    /**
     * @brief StringToSign:组织参与签名计算的字符串
     * @return
     */
    QString StringToSign();

    /**
     * @brief UrlTosign:生成用于参与签名的Url
     * @return
     */
    QString UrlToSign();

    /**
     * @brief QueryParameter :该函数用于接受Query部分的参数
     * @param pamemter：      传入的QMap容器，内涵Query的键对值
     */
    void  QueryParameter(const QMap<QString,QString> pamemter);



signals:
    /**
     * @brief sendreply :该函数的作用书返回成功连接时返回的reply句柄，以便于外界调用接收回馈数据。
     * @param reply ：replay句柄
     * @param apiindex ：对应的哪一个API请求
     */
    void sendreply(QNetworkReply * reply,int apiindex);

public slots:

private:
    QString ak_id = AppKey;           //key
    QString ak_secret = AppSecret;    //secret
    QString requset_api ;
    int apiindex;

    // request header
    QMap<QString,QString> header;
    // 参与签名的header
    QMap<QString,QString> signatureheader;
    // Body字节流
    QByteArray bodystream;
    // queryparams的参数,包括Query与Body中的Form参数
    QMap<QString,QString> queryparams;
    // 整体的url地址
    QUrl url;
    // 网络连接管理类
    QNetworkAccessManager *manager;
    // 服务器返回
    QNetworkReply   *reply;
    // 单例类json
    MyJson *myjson;
};

#endif // ALIAPI_H
