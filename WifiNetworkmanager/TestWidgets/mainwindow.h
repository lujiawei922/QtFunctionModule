#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableView>
#include "../NetworkManager/wifimodel.h"
#include "../NetworkManager/buttondelegate.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void showpasswordDialg(QString wifiname);

private:
    Ui::MainWindow *ui;
    WifiModel *my_model;
    ButtonDelegate *mydelete;
    NetworkManager* instance = NetworkManager::Instance();
};

#endif // MAINWINDOW_H
