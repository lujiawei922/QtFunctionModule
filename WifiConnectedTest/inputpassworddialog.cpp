#include "inputpassworddialog.h"

InputPasswordDialog::InputPasswordDialog(QWidget *parent)
    : QWidget(parent)
{
    this->guiInit();
    QDesktopWidget desktop;
    this->setFixedSize(desktop.width()/3,desktop.height()/4);
}

void InputPasswordDialog::guiInit()
{
    QLabel *inputLabel = new QLabel(this);
    inputLabel->setText(tr("Password"));
    inputLabel->setAlignment(Qt::AlignCenter);
    inputLabel->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    inputLabel->setFixedHeight(30);

    QLineEdit *inputLine = new QLineEdit(this);
    inputLine->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Fixed);
    inputLine->setFixedHeight(30);

    QPushButton *okBtn = new QPushButton(this);
    okBtn->setText(tr("OK"));
    okBtn->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Fixed);
    okBtn->setFixedHeight(30);

    QPushButton *cancelBtn = new QPushButton(this);
    cancelBtn->setText(tr("Cancel"));
    cancelBtn->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Fixed);
    cancelBtn->setFixedHeight(30);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(inputLabel,0,0,1,1);
    layout->addWidget(inputLine,0,1,1,2);
    layout->addWidget(okBtn,1,1,1,1);
    layout->addWidget(cancelBtn,1,2,1,1);
    this->setLayout(layout);

    connect(okBtn,&QPushButton::clicked,[=](){
        if(inputLine->text().isEmpty()){
            emit confirmPassword(inputLine->text());
        }
    });
}
