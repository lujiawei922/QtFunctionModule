#ifndef WIFIMODEL_H
#define WIFIMODEL_H

#include <QAbstractTableModel>
#include "networkmanager.h"

class WifiModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit WifiModel(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    bool setdata();
public slots:
    void refrushModel();

private:
    QStringList m_header;
    NetworkManager* instance = NetworkManager::Instance();

};

#endif // WIFIMODEL_H
