#ifndef INPUTPASSWORDDIALOG_H
#define INPUTPASSWORDDIALOG_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QGridLayout>
#include <QDesktopWidget>

class InputPasswordDialog : public QWidget
{
    Q_OBJECT
public:
    explicit InputPasswordDialog(QWidget *parent = nullptr);

signals:
    void confirmPassword(const QString &password);

private slots:
    void guiInit();

};

#endif // INPUTPASSWORDDIALOG_H
