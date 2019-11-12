#include "buttondelegate.h"
#include <QDebug>
#include <QMouseEvent>
#include <QDialog>
#include <QDesktopWidget>
#include "passworddialog.h"

const int FILE_OPERATE_COLUMN = 2;//按键所在列

ButtonDelegate::ButtonDelegate(QObject *parent) :
    QItemDelegate(parent)
{

}

ButtonDelegate::~ButtonDelegate()
{
    QMap<QModelIndex, QStyleOptionButton*>::iterator it;
    for (it = m_btns.begin();it != m_btns.end(); it++)
    {
        if(it.value() != nullptr)
        {
            delete it.value();
            it.value() = nullptr;
        }
    }
}

void ButtonDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    //在特定的索引处绘制按键，这个变量临时存储绘制的按键信息
    QStyleOptionButton* button = m_btns.value(index);
    //如果为按键列绘制按键
    if (index.column() == FILE_OPERATE_COLUMN) {
        //进行判断，如果是Map容器中没有，则为它动态分配内存
        if(button == nullptr)
        {
            button = new QStyleOptionButton();//绘制存button的参数的对象
            button->features = QStyleOptionButton::None;//设置为pushButton类型，可以按下
            button->rect = option.rect.adjusted(1, 1, -1, -1);//绘制尺寸

            button->state |= QStyle::State_Enabled;
            (const_cast<ButtonDelegate *>(this))->m_btns.insert(index, button);//将绘制的按键放入Qmap
        }

        if(instance->wifiList().operator[](index.row()).operator[](ESSID_STATUS) != "COMPLETED")
        {
            button->text = tr("连接");
        }
        else {
            button->text = tr("已连接");
        }
    }

    painter->save();
    if (option.state & QStyle::State_Selected)
    {
        painter->fillRect(option.rect, option.palette.highlight());
    }
    painter->restore();

    QApplication::style()->drawControl(QStyle::CE_PushButton, button, painter);
}

bool ButtonDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
{
    if (event->type() == QEvent::MouseButtonPress)
    {

        QMouseEvent* e =(QMouseEvent*)event;
        //确定鼠标点击的位置在画的按键中
        if (option.rect.adjusted(1, 1, -1, -1).contains(e->x(), e->y()) && m_btns.contains(index))
        {
            qDebug()<<"--------";
            m_btns.value(index)->state |= QStyle::State_Sunken;

        }
    }
    if (event->type() == QEvent::MouseButtonRelease)
    {
        //qDebug()<<"++++++++";
        QMouseEvent* e =(QMouseEvent*)event;
        if (option.rect.adjusted(1, 1, -1, -1).contains(e->x(), e->y()) && m_btns.contains(index))
        {
            m_btns.value(index)->state &= (~QStyle::State_Sunken);
            emit buttonclicked(instance->wifiList().operator[](index.row()).operator[](ESSID_BSSID));
        }
    }
    return true;
}
