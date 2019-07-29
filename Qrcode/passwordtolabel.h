#ifndef PASSWORDTOLABEL_H
#define PASSWORDTOLABEL_H

#include <QObject>
#include <QDebug>
#include <QPainter>
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
     * @param height ： 设置二维码高
     */
    void setLabelGeometry(int width,int height);
    QPixmap GenerateQRcode(QString tempstr);



signals:

public :
    qint32 temp_width;
    qint32 temp_height;

};

#endif // PASSWORDTOLABEL_H
