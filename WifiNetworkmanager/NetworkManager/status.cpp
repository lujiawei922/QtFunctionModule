#include "status.h"
#include <QApplication>
#include <QDebug>
Status::Status(QObject *parent):
    QItemDelegate(parent),
    update_button(new QPushButton())
{

}

Status::~Status()
{

}

void Status::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if(index.column() == 2)
    {
        int top = option.rect.top();
        int left = option.rect.left();
        int width = option.rect.width();
        int height = option.rect.height();

        QStyleOptionButton button;
        button.rect.setRect(left,top,width,height);
        button.text = QObject::tr("连接");
        //button.state |= QStyle::State_Enabled;
        QApplication::style()->drawControl(QStyle::CE_PushButton, &button, painter,update_button.data());
    }
    else
    {
        QItemDelegate::paint(painter,option,index);
    }
}

//QWidget *Status::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
//{
//    QPushButton *detail = new QPushButton("Detail",parent);
//    detail->setText("Detail");
//    return detail;
//}

//void Status::setEditorData(QWidget *editor, const QModelIndex &index) const
//{
//    QPushButton *detail = qobject_cast<QPushButton *>(editor);
//    detail->setProperty("Detail", "Detail");
//    detail->setText("Detail");
//}

//void Status::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
//{
//    QPushButton *detail = qobject_cast<QPushButton *>(editor);
//    model->setData(index, detail->property("Detail"));
//}

//void Status::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
//{
//    editor->setGeometry(option.rect);
//    (void) index;
//}
