#include "stopartnerview.h"

STOPartnerView::STOPartnerView(QObject *parent) : QAbstractTableModel(parent) {}

void STOPartnerView::addSTOPartner(STOPartner *STOPartner) {
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    stoPartners.append(STOPartner);
    endInsertRows();
}

void STOPartnerView::removeSTOPartner(int row) {
    beginRemoveRows(QModelIndex(), row, row);
    delete stoPartners.takeAt(row);
    endRemoveRows();
}

int STOPartnerView::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return stoPartners.count();
}

int STOPartnerView::columnCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return 5;
}

QVariant STOPartnerView::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || role != Qt::DisplayRole) {
        return QVariant();
    }

    const STOPartner *stoPartner = stoPartners.at(index.row());

    switch (index.column()) {
    case 0:
        return stoPartner->getId();
    case 1:
        return stoPartner->getAddress();
    case 2:
        return stoPartner->getNumber();
    case 3:
        return stoPartner->getDateStart();
    case 4:
        return stoPartner->getDateFinal();
    default:
        return QVariant();
    }
}

STOPartner* STOPartnerView::getSTOPartner(int row) const {
    if (row < 0 || row >= stoPartners.count()) {
        return nullptr;
    }
    return stoPartners.at(row);
}

STOPartner *STOPartnerView::findSTOPartnerById(int id) const {
    for (const STOPartner *stoPartner : stoPartners) {
        if (stoPartner->getId() == id) {
            return const_cast<STOPartner *>(stoPartner);
        }
    }
    return nullptr;
}

QVariant STOPartnerView::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole || orientation != Qt::Horizontal) {
        return QVariant();
    }

    switch (section) {
    case 0:
        return "ID Записи";
    case 1:
        return "Адрес";
    case 2:
        return "Номер договора";
    case 3:
        return "Дата начала";
    case 4:
        return "Дата окончания";
    default:
        return QVariant();
    }
}
