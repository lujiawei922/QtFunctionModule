#include "passworddialog.h"
#include "ui_passworddialog.h"

PasswordDialog::PasswordDialog(QWidget *parent,QString bssid) :
    QDialog(parent),
    bssid(bssid),
    ui(new Ui::PasswordDialog)
{
    ui->setupUi(this);
    setAttribute (Qt::WA_DeleteOnClose);
    connect(this,&PasswordDialog::setPassword,instance,&NetworkManager::setCurrentWifi);
}

PasswordDialog::~PasswordDialog()
{
    delete ui;
}

void PasswordDialog::on_buttonBox_accepted()
{
    QString password;
    password = ui->lineEdit->text();
    emit setPassword(bssid,password);
}
