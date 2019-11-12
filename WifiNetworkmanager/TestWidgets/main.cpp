#include "mainwindow.h"
#include <QApplication>
#include "networkmanager.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    qputenv("QT_IM_MODULE", "tgtsml");
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //NetworkManager* instance = NetworkManager::Instance();



    return a.exec();
}
