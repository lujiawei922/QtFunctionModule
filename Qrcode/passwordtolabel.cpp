#include "passwordtolabel.h"
#include "qrencode.h"

Passwordtolabel::Passwordtolabel(QObject *parent) : QObject(parent)
{

}

Passwordtolabel::~Passwordtolabel()
{

}

void Passwordtolabel::setLabelGeometry(int width,int height)
{
    temp_width=width; //二维码图片的大小
    temp_height=height;
}

QPixmap Passwordtolabel::GenerateQRcode(QString tempstr)
{
    //二维码数据
    QRcode *qrcode;
    qrcode = QRcode_encodeString(tempstr.toStdString().c_str(), 2, QR_ECLEVEL_Q, QR_MODE_8, 1);
    qint32 qrcode_width = qrcode->width > 0 ? qrcode->width : 1;
    //二维码图片的缩放比例,尽管老的强制类型转换也可以，但是有警告，强迫症受不了
    double scale_x = static_cast < double > (temp_width) / static_cast < double > (qrcode_width);
    double scale_y =static_cast < double > (temp_height) /static_cast < double > (qrcode_width);

    QImage mainimg=QImage(temp_width,temp_height,QImage::Format_ARGB32);
    QPainter painter(&mainimg);
    QColor background(Qt::white);
    painter.setBrush(background);
    painter.setPen(Qt::NoPen);
    painter.drawRect(0, 0, temp_width, temp_height);
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
    QPixmap mainmap=QPixmap::fromImage(mainimg);

    return mainmap;
}


