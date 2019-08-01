#include "passwordtolabel.h"
#include "./qrencode/qrencode.h"

Passwordtolabel::Passwordtolabel(QObject *parent) : QObject(parent)
{

}

Passwordtolabel::~Passwordtolabel()
{

}

void Passwordtolabel::setLabelGeometry(int width,int height,int strheight)
{
    temp_width = width;
    temp_height = height;
    str_height = strheight;
}

QPixmap Passwordtolabel::GenerateQRcode(QString tempstr)
{
    //二维码数据
    QRcode *qrcode;
    qrcode = QRcode_encodeString(tempstr.toStdString().c_str(), 2, QR_ECLEVEL_Q, QR_MODE_8, 1);
    qint32 qrcode_width = qrcode->width > 0 ? qrcode->width : 1;
    //二维码图片的缩放比例,尽管老的强制类型转换也可以，但是有警告，强迫症受不了
    double scale_x = static_cast < double > (temp_width) / static_cast < double > (qrcode_width);
    double scale_y =static_cast < double > (temp_height - str_height) /static_cast < double > (qrcode_width);

    QImage mainimg=QImage(temp_width,temp_height,QImage::Format_ARGB32);
    QPainter painter(&mainimg);
    QColor background(Qt::transparent);
    painter.setBrush(background);
    painter.setPen(Qt::NoPen);
    painter.drawRect(0, 0, temp_width, temp_height - str_height);
    QColor foreground(Qt::black);
    painter.setBrush(foreground);
    for( qint32 y = 0; y < qrcode_width; y ++)
    {
        for(qint32 x = 0; x < qrcode_width; x++)
        {
            unsigned char b = qrcode->data[y * qrcode_width + x];
            if(b & 0x01)
            {
                QRectF r(x * scale_x, y * scale_y, scale_x, scale_y);
                painter.drawRects(&r, 1);
            }
        }
    }

    //在二维码下面添加字符
    if(str_height > 0)
    {

        painter.setPen(strcolor);
        QFont font(family, pointSize, weight,italic);
        painter.setFont(font);
        QRect  mainrect= mainimg.rect();
        mainrect.setHeight(temp_height + (font.pointSize() + 3) - str_height );
        painter.drawText(mainrect, Qt::AlignBottom | Qt::AlignCenter,tempstr);
    }

    QPixmap mainmap=QPixmap::fromImage(mainimg);
    QRcode_free(qrcode);


    return mainmap;
}


