#ifndef WIFICONNECTTEST_H
#define WIFICONNECTTEST_H

#include <QWidget>
#include <QFile>
#include <QDebug>
#include <QGridLayout>
#include <QPainter>
#include <QPixmap>
#include <QPen>
#include <QDialog>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QMouseEvent>
#include <QNetworkConfigurationManager>
#include <QDesktopWidget>
#include <QLabel>
#include "inputpassworddialog.h"

#define WIFINUM 10                              //最多显示10个wifi

class WifiConnectTest : public QWidget
{
    Q_OBJECT

public:
    WifiConnectTest(QWidget *parent = 0);
    ~WifiConnectTest();
private slots:
    void wifiListInit();

protected:
    bool eventFilter(QObject *obj, QEvent *event);

private:
    QLabel *iconLabel[WIFINUM];                 //显示wifi信号强度
    QLabel *connectLabel[WIFINUM];              //显示wifi连接状态
    QLabel *wifiNameLabel[WIFINUM];             //wifi名
    QWidget *wifiWidget[WIFINUM];               //包含wifi成员的widget
    QPushButton *connectButton[WIFINUM];        //wifi连接按钮
};

#endif // WIFICONNECTTEST_H
