#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../NetworkManager/passworddialog.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    my_model = new WifiModel(this);
    mydelete = new ButtonDelegate(this);
    connect(mydelete,&ButtonDelegate::buttonclicked,this,&MainWindow::showpasswordDialg);
    connect(instance,&NetworkManager::sigRefreshed,my_model,&WifiModel::refrushModel);

    ui->wifitableView->setModel(my_model);
    ui->wifitableView->setItemDelegateForColumn(2,mydelete);
    ui->wifitableView->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showpasswordDialg(QString bssid)
{
    QDialog *d = new PasswordDialog(this,bssid);
    d->setWindowModality(Qt::WindowModal);

    //d->move(QApplication::desktop()->screenGeometry().center() - d->rect().center());
    d->show();
}
