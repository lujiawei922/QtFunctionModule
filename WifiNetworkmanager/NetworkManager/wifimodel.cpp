#include "wifimodel.h"

WifiModel::WifiModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    m_header<<tr("强度")<<tr("名称")<<tr("状态");
}

QVariant WifiModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
    if(role==Qt::DisplayRole&&orientation==Qt::Horizontal)
    {

        return m_header[section];
    }

    return QAbstractTableModel::headerData(section,orientation,role);
}

int WifiModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    //return 3;
    return instance->wifiList().size();

}

int WifiModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return 3;
}

QVariant WifiModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    if(role == Qt::DisplayRole)
    {
        QString value;
        switch (index.column()) {
        case 0:
        value = instance->wifiList().operator[](index.row()).operator[](ESSID_SIGNAL);
        break;

        case 1:
        value = instance->wifiList().operator[](index.row()).operator[](ESSID_NAME);
        break;

        default:
        break;

        }
        return value;

    }

    return QVariant();
}

void WifiModel::refrushModel()
{
    beginResetModel();
    endResetModel();
}
