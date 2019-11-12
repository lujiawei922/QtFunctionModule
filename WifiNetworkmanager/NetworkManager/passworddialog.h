#ifndef PASSWORDDIALOG_H
#define PASSWORDDIALOG_H

#include <QDialog>
#include "networkmanager.h"

namespace Ui {
class PasswordDialog;
}

class PasswordDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PasswordDialog(QWidget *parent = nullptr,QString bssid = "");
    ~PasswordDialog();
signals:
    void setPassword(QString bssid,QString password);

private slots:
    void on_buttonBox_accepted();

private:
    QString bssid;
    Ui::PasswordDialog *ui;
    NetworkManager* instance = NetworkManager::Instance();
};

#endif // PASSWORDDIALOG_H
