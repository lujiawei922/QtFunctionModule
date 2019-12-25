#include "wificonnecttest.h"

const QString wifiStrList = QString("/Settings/WiFi/wifi.ini");

WifiConnectTest::WifiConnectTest(QWidget *parent)
    : QWidget(parent)
{
    this->wifiListInit();
    QDesktopWidget desktop;
    this->setFixedSize(desktop.width()/2,desktop.height()/2);
    system("sudo nmcli r wifi on");
    system("sudo nmcli dev wifi > /Settings/WiFi/wifi.ini");
//    system("sudo nmcli con > /Settings/WiFi/wifiCon.ini");
}

WifiConnectTest::~WifiConnectTest()
{

}

void WifiConnectTest::wifiListInit()
{
    QFile file(wifiStrList);
    if(!file.open(QIODevice::ReadOnly)){
        qDebug()<<"No such file!";
        return;
    }
    int curLine = 0;
    QString line;

    QVBoxLayout *vLayout = new QVBoxLayout;
    if(file.size()!=0){
        QTextStream in(&file);
        QString signalFlag = "SIGNAL";      //表示wifi信号字符
        QString wifiFlag = "SSID";          //wifi名字符
        QString modeFlag = "MODE";          //wifi连接模式

        line =  in.readLine();
        if(!line.isEmpty()){
            int signalIndex = line.indexOf(signalFlag);     //文件对应的wifi信号强度索引值
            int wifiIndex = line.indexOf(wifiFlag);         //文件对应的wifi名索引值
            int modeIndex = line.indexOf(modeFlag);
            while (curLine < WIFINUM) {
                line =  in.readLine();
                QString tmpStr = line;
                QString curConnection = line.left(1);       //已连接wifi判断
                QString wifiName = line.mid(wifiIndex,(modeIndex-wifiIndex)).simplified();  //获取wifi名称
                int signalValue = tmpStr.mid(signalIndex,3).simplified().toInt();           //获取wifi的信号强度
                if(!wifiName.isEmpty()){
                    QGridLayout *gridLayout = new QGridLayout();
                    wifiWidget[curLine] = new QWidget(this);                                //wifi对应的属性栏
                    wifiWidget[curLine]->setObjectName(QString("wifiName*%1*%2").arg(QString::number(curLine)).arg(wifiName));
                    wifiWidget[curLine]->installEventFilter(this);                          //安装事件过滤器，选中wifi后弹出连接wifi的接口按钮
                    wifiWidget[curLine]->setStyleSheet(QString("QWidget::hover{background-color:darkgray}").append(QString("QWidget{background-color:transparent;}")));

                    wifiNameLabel[curLine] = new QLabel(wifiWidget[curLine]);
                    wifiNameLabel[curLine]->setText(wifiName);                              //显示wifi名

                    QPixmap pix = QPixmap(60,40);       //根据wifi信号强度绘制wifi信号
                    pix.fill(Qt::transparent);
                    QPainter paint(&pix);
                    QPen pen = QPen();
                    pen.setColor(Qt::darkGreen);
                    pen.setWidth(4);
                    paint.setPen(pen);
                    for(int k=2;k<7;k++){
                        if(k == (signalValue/20+3)){
                            QPen penGray = QPen();
                            penGray.setColor(Qt::gray);
                            penGray.setWidth(4);
                            paint.setPen(penGray);
                        }
                        paint.drawLine(8*k,48-7*k,8*k,35);
                    }
                    paint.end();

                    iconLabel[curLine] = new QLabel(wifiWidget[curLine]);
                    iconLabel[curLine]->setPixmap(pix); //添加wifi信号强度图标

                    connectLabel[curLine] = new QLabel(wifiWidget[curLine]);
                    if(curConnection=="*")              //wifi连接状态，wifi名前如果有"*",表示当前wifi处于连接状态
                        connectLabel[curLine]->setText("已连接");

                    connectButton[curLine] = new QPushButton(wifiWidget[curLine]);
                    connectButton[curLine]->setStyleSheet(QString("QPushButton{background-color:lightgray;}").append(QString("QPushButton::pressed{background-color:darkgray;}")));
                    connectButton[curLine]->setText(tr("连接"));
                    connectButton[curLine]->setVisible(false);

                    gridLayout->addWidget(wifiNameLabel[curLine],0,0,1,3);      //在wifi属性框中添加wifi对应的属性信息
                    gridLayout->addWidget(connectLabel[curLine],0,3,1,1);
                    gridLayout->addWidget(iconLabel[curLine],0,4,1,1);
                    gridLayout->addWidget(connectButton[curLine],1,3,1,1);
                    gridLayout->setMargin(0);
                    gridLayout->setSpacing(0);
                    wifiWidget[curLine]->setLayout(gridLayout);

                    vLayout->addWidget(wifiWidget[curLine]);
                    vLayout->setMargin(2);
                    vLayout->setSpacing(0);
                }
                curLine++;
            }
        }
    }
    file.close();
    this->setLayout(vLayout);
}

bool WifiConnectTest::eventFilter(QObject *obj, QEvent *event)
{
    QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
    if(mouseEvent->type() == QEvent::MouseButtonPress){
        if(mouseEvent->button()==Qt::LeftButton){
            if(obj->objectName().contains("wifiName")){
                QString wifiName = obj->objectName().section('*',-1);
                static int curLine = 0;
                connectButton[curLine]->setVisible(false);                  //隐藏所有wifi连接button
                curLine = obj->objectName().section('*',1,1).toInt();
                connectButton[curLine]->setVisible(true);                   //选中当前wifi属性框后，显示wifi连接按钮

                connect(connectButton[curLine],&QPushButton::clicked,[=](){
                    InputPasswordDialog *inputPassword = new InputPasswordDialog();     //实例化wifi密码输入窗口
                    inputPassword->show();
                    connect(inputPassword,&InputPasswordDialog::confirmPassword,[=](QString password){
                        QString connectNetWorkStr = QString("nmcli dev wifi connect %1 password %2");
                        QByteArray array = connectNetWorkStr.arg(wifiName).arg(password).toLatin1();
                        char *cmdStr = array.data();        //QString 转 char*
                        if(-1!=system(cmdStr)){
                            QNetworkConfigurationManager mgr;
                            if(mgr.isOnline()){             //wifi已连接
                                qDebug("wifi is online!");
                                connectButton[curLine]->setText(tr("已连接"));
                            }
                            else{
                                qDebug("wifi is offline!");
                                connectButton[curLine]->setText(tr("offline"));
                            }
                        }
                    });
                });
                return true;
            }
        }
    }
    return QWidget::eventFilter(obj, event);
}
