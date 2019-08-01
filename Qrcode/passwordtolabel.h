#ifndef PASSWORDTOLABEL_H
#define PASSWORDTOLABEL_H

#include <QObject>
#include <QDebug>
#include <QPainter>
#include <QColor>

//二维码底下字体颜色
const QColor strcolor = Qt::red;
//文字字体
const QString family = "宋体";
//设置点大小，-1为默认12
const int pointSize = -1;
//笔画粗细
const int weight = QFont::Bold;
//字体倾斜
const bool italic = false;

/**
 * @ClassName: Passwordtolabel
 * @Description: 根据字符串生成二维码
 * @Autor: lujiawei LJW@lierda.com
 * @date: 2019-07-23
 * @Version: 1.0.0
 * @update_autor
 * @update_time
**/

class Passwordtolabel : public QObject
{
    Q_OBJECT
public:
    explicit Passwordtolabel(QObject *parent = nullptr);
    ~Passwordtolabel();
    /**
     * @brief setLabelwidth ：设置二维码宽高
     * @param width : 二维码宽
     * @param height ： 设置二维码与字符总高度
     * @param str_height: 二维码底下字符宽度
     */
    void setLabelGeometry(int width,int height,int str_height = 0);
    QPixmap GenerateQRcode(QString tempstr);


signals:

public :
    qint32 temp_width;
    qint32 temp_height;
    qint32 str_height;

};

#endif // PASSWORDTOLABEL_H
