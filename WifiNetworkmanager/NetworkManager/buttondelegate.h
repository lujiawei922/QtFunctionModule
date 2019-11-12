#ifndef BUTTONDELEGATE_H
#define BUTTONDELEGATE_H

#include <QObject>
#include <QItemDelegate>
#include <QPainter>
#include <QApplication>
#include "networkmanager.h"

class ButtonDelegate : public QItemDelegate
{
    Q_OBJECT

 public:
     explicit ButtonDelegate(QObject *parent = nullptr);
     ~ButtonDelegate();
 //重写绘图事件
     void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
 //重写事件过滤
     bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index);

 signals:
     void buttonclicked(QString wifiname);

 private:
     QMap<QModelIndex, QStyleOptionButton*> m_btns;
     NetworkManager* instance = NetworkManager::Instance();

};

#endif // BUTTONDELEGATE_H
