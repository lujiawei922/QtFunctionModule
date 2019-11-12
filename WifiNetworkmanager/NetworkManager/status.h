#ifndef STATUS_H
#define STATUS_H

#include <QPushButton>
#include <QScopedPointer>
#include <QItemDelegate>

class Status : public QItemDelegate
{
    Q_OBJECT
public:
    explicit Status(QObject *parent = nullptr);
    ~Status();

    /**
     * @brief paint     对视图的单元显示进行重绘
     * @param painter   画笔
     * @param option    显示风格
     * @param index     单元索引
     */
    void paint(QPainter *painter,const QStyleOptionViewItem & option,const QModelIndex &index )const;

//    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;

//    void setEditorData(QWidget *editor, const QModelIndex &index) const;

//    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;

//    void updateEditorGeometry(QWidget *editor,const QStyleOptionViewItem &option,const QModelIndex &index) const;
private:
    QScopedPointer<QPushButton> update_button;
};

#endif // STATUS_H
