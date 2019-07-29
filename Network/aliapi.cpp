#include "aliapi.h"

AliApi::AliApi(int apiindex,QMap<QString,QString> &querypam,QObject *parent) :
    QObject(parent),
    requset_api(ReqApi.value(apiindex)),
    apiindex(apiindex),
    queryparams(querypam)
{
    HeaderInit();
    manager =new QNetworkAccessManager(this);
    myjson = MyJson::getInstance();
    //建立与MyJson单例类的信号槽连接
    connect(this,&AliApi::sendreply,myjson,&MyJson::getreply);
}


void AliApi::CopyBodyStream(const QByteArray &t_bodystream)
{
    bodystream = t_bodystream;
}

QByteArray AliApi::GetMD5(QByteArray bytes_)
{
    QCryptographicHash ch(QCryptographicHash::Md5);
    QByteArray ret;
    ch.addData(bytes_);
    ret = ch.result().toBase64();
    return ret;
}

void AliApi::HMACSha256(QByteArray key, QByteArray baseString)
{
    qDebug()<<"baseString:"<<baseString<<__LINE__;
    qDebug()<<"baseStringToHex:"<<baseString.toHex(':')<<__LINE__;
    QByteArray sign = QMessageAuthenticationCode::hash(baseString,key,QCryptographicHash::Sha256).toBase64();
    QString signature = sign;

    header.insert("X-Ca-Signature",signature.toLatin1());
    qDebug() << "sign:" << sign;

}

QString AliApi::StringToSign()
{
    QString signheader;     //用于签名计算的header
    QString signurl;        //用于签名的url

    //生成body的MD5值并返回给header.value("");ps:现在都使用GET请求，无body，所以这段代码没有测试过
    //qDebug()<<"bodystream lenth:"<<bodystream.length();
    if(!(bodystream.length() == 0))
    {
        header["Content-MD5"] = GetMD5(bodystream);
    }

    //获取时间
    QLocale lo = QLocale::English;                                       //设置QLocale为英文
    header["Date"] = lo.toString(QDateTime::currentDateTime(),"ddd dd MMM yyyy hh:mm:ss")+QString(" GMT+0800 (CST)");
    qDebug() << "Date:"<<header.value("Date");

    //生成随机数
    QUuid id = QUuid::createUuid();
    header["X-Ca-Nonce"] = id.toString().remove("{").remove("}"); //获取UUid并去除左右括号
    qDebug()<< "X-Ca-Nonce:"<<header.value("X-Ca-Nonce");

    /*
     *遍历header中的key值，将X-Ca但不包括X-Ca-Signature、X-Ca-Signature-Headers的键加入X-Ca-Signature-Headers的value中,
     * 将键对值加入signatureheader中
     */
    QMap<QString,QString>::iterator it;
    for(it = header.begin();it != header.end(); ++it)
    {
        if(!(it.key().startsWith("X-Ca-",Qt::CaseInsensitive)))
        {
            continue;
        }

        if(it.key().compare("X-Ca-Signature",Qt::CaseInsensitive)==0 || it.key().compare("X-Ca-Signature-Headers",Qt::CaseInsensitive)==0)
        {
            continue;
        }
        header["X-Ca-Signature-Headers"].append(it.key()+',');

        signatureheader.insert(it.key(),it.value());
    }
    //去掉最后一个','
    if(header["X-Ca-Signature-Headers"].right(1) == ',')
    {
        header["X-Ca-Signature-Headers"].chop(1);
    }
    qDebug()<<"X-Ca-Signature-Headers:"<<header.value("X-Ca-Signature-Headers");

    //将signatureheader键对值拼接成字符串
    for(it = signatureheader.begin();it != signatureheader.end(); ++it)
    {
        signheader.append(it.key().toLower() + ':' + it.value());
        if(it != signatureheader.end() - 1 )
        {
            signheader.append("\n");
        }
    }
    qDebug()<<"signheader:"<<signheader;

    signurl = UrlToSign();
    qDebug()<<"signurl:"<<signurl;

    QString ret = header.value("HTTPMethod") + "\n" + header.value("Accept") + "\n" + header.value("Content-MD5") + "\n"
            + header.value("Content-Type") + "\n" + header.value("Date") + "\n" + signheader +"\n" + signurl ;

    QString temp = ret;
    qDebug()<<"temp:"<<temp.replace(QRegExp("\n"), "#").toUtf8().toHex(':');

    return ret;

}

QString AliApi::UrlToSign()
{
    QString url = requset_api;
    //如果参数为空，直接返回
    if(queryparams.empty())
    {
        return url;
    }
    else
    {
        url.append('?');

        QMap<QString,QString>::iterator it; //遍历map
        for(it = queryparams.begin(); it != queryparams.end();++it)
        {
            //如果某个参数的 Value 为空只保留 Key 参与签名，等号不需要再加入签名
            if(it.value().length() == 0)
            {
                url.append(it.key());
                if( it != queryparams.end() - 1)
                {
                    url.append('&');
                }
            }
            else
            {
                url.append(it.key() + '=' + it.value().toUtf8());
                if( it != queryparams.end() - 1)
                {
                    url.append('&');
                }
            }
        }

        return url;
    }
}

void AliApi::QueryParameter(const QMap<QString, QString> pamemter)
{
    queryparams = pamemter;
}

void AliApi::NetworkRequest()
{
    //获取签名
    HMACSha256(ak_secret.toLatin1(),StringToSign().toUtf8());
    QNetworkRequest request;

    url = QUrl(("http://" + header.value("HOST") + '/' + UrlToSign()));
    qDebug()<<"url:"<<url;

    request.setUrl(url);

    request.setHeader(QNetworkRequest::ContentTypeHeader,header.value("Content-Type").toLatin1());
    request.setRawHeader(QByteArray("Accept"),header.value("Accept").toLatin1());
    request.setRawHeader(QByteArray("HOST"),header.value("HOST").toLatin1());
    request.setRawHeader(QByteArray("Date"),header.value("Date").toLatin1());
    request.setRawHeader(QByteArray("Content-MD5"),header.value("Content-MD5").toLatin1());
    request.setRawHeader(QByteArray("X-Ca-Key"),header.value("X-Ca-Key").toLatin1());
    request.setRawHeader(QByteArray("X-Ca-Nonce"),header.value("X-Ca-Nonce").toLatin1());
    request.setRawHeader(QByteArray("X-Ca-Signature"),header.value("X-Ca-Signature").toLatin1());
    request.setRawHeader(QByteArray("X-Ca-Signaturemethod"),header.value("X-Ca-SignatureMethod").toLatin1());
    request.setRawHeader(QByteArray("X-Ca-Signature-Headers"),header.value("X-Ca-Signature-Headers").toLower().toLatin1());



    qDebug()<<"request:"<<request.rawHeaderList();


    //添加事件循环机制。返回后再运行后面的
    QEventLoop eventLoop;
    reply = manager->get(request);
    //qDebug()<<__FILE__<<__FUNCTION__<<__LINE__;
    connect(reply,&QNetworkReply::finished,&eventLoop,&QEventLoop::quit);

    qDebug()<<"connect...";
    eventLoop.exec();
    qDebug()<<"end...";

    //错误处理
    if(reply->error() == QNetworkReply::NoError)
    {
        qDebug() << "request protobufHttp NoError";
        //发送信号
        emit sendreply(reply,apiindex);
    }
    else {
        qDebug()<<"request protobufHttp handle errors here";
        QVariant statusCodeV = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
        //statusCodeV是HTTP服务器的相应码，reply->error()是Qt定义的错误码，可以参考QT的文档
        qDebug()<<"request protobufHttp found error ....code:"<< statusCodeV.toInt() <<reply->error();
        qDebug()<<qPrintable(reply->errorString());
    }
}

void AliApi::HeaderInit()
{
    header.insert("HTTPMethod",HTTPMethod);
    header.insert("Content-Type",Content_Type);


    header.insert("Accept",Accept);
    header.insert("HOST",HOST);
    header.insert("Date","");
    header.insert("Content-MD5","");//初版
    header.insert("X-Ca-Key",ak_id);
    header.insert("X-Ca-Nonce","");
    header.insert("X-Ca-Signature","");
    header.insert("X-Ca-SignatureMethod",X_Ca_SignatureMethod);
    header.insert("X-Ca-Signature-Headers","");
}
