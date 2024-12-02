#include "rentview.h"

RentView::RentView(QObject *parent) : QAbstractTableModel(parent) {}

void RentView::addRent(Rent *rent) {
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    rents.append(rent);
    endInsertRows();
}

void RentView::removeRent(int row) {
    beginRemoveRows(QModelIndex(), row, row);
    delete rents.takeAt(row);
    endRemoveRows();
}

int RentView::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return rents.count();
}

int RentView::columnCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return 5;
}

Rent* RentView::getRent(int row) const {
    if (row < 0 || row >= rents.count()) {
        return nullptr;
    }
    return rents.at(row);
}

Rent *RentView::findRentById(int id) const {
    for (const Rent *rent : rents) {
        if (rent->getId() == id) {
            return const_cast<Rent *>(rent);
        }
    }
    return nullptr;
}

QVariant RentView::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || role != Qt::DisplayRole) {
        return QVariant();
    }

    const Rent *rent = rents.at(index.row());

    switch (index.column()) {
    case 0:
        return rent->getId();
    case 1:
        return rent->getClientId();
    case 2:
        return rent->getCarId();
    case 3:
        return rent->getStartRent();
    case 4:
        return rent->getEndRent();
    default:
        return QVariant();
    }
}

QVariant RentView::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole || orientation != Qt::Horizontal) {
        return QVariant();
    }

    switch (section) {
    case 0:
        return "ID";
    case 1:
        return "ID Клиента";
    case 2:
        return "ID Автомобиля";
    case 3:
        return "Время начала";
    case 4:
        return "Время окончания";
    default:
        return QVariant();
    }
}
