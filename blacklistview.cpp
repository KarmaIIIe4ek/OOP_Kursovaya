#include "blacklistview.h"

BlacklistView::BlacklistView(QObject *parent) : QAbstractTableModel(parent) {}

void BlacklistView::addBlacklist(Blacklist *blacklist) {
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    blacklists.append(blacklist);
    endInsertRows();
}

bool BlacklistView::removeBlacklist(int row) {
    Blacklist *temp = blacklists.takeAt(row);
    beginRemoveRows(QModelIndex(), row, row);
    delete temp;
    endRemoveRows();
    return true;
}

int BlacklistView::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return blacklists.count();
}

int BlacklistView::columnCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return 4;
}

QVariant BlacklistView::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || role != Qt::DisplayRole) {
        return QVariant();
    }

    const Blacklist *blacklist = blacklists.at(index.row());

    switch (index.column()) {
    case 0:
        return blacklist->getId();
    case 1:
        return blacklist->getIdClient();
    case 2:
        return blacklist->getDate();
    case 3:
        return blacklist->getReason();
    default:
        return QVariant();
    }
}

Blacklist* BlacklistView::getBlacklist(int row) const {
    if (row < 0 || row >= blacklists.count()) {
        return nullptr;
    }
    return blacklists.at(row);
}

Blacklist *BlacklistView::findBlacklistById(int id) const {
    for (const Blacklist *blacklist : blacklists) {
        if (blacklist->getId() == id) {
            return const_cast<Blacklist *>(blacklist);
        }
    }
    return nullptr;
}

Blacklist *BlacklistView::findBlacklistByIdClient(int id) const {
    for (const Blacklist *blacklist : blacklists) {
        if (blacklist->getIdClient() == id) {
            return const_cast<Blacklist *>(blacklist);
        }
    }
    return nullptr;
}

QVariant BlacklistView::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole || orientation != Qt::Horizontal) {
        return QVariant();
    }

    switch (section) {
    case 0:
        return "ID Записи";
    case 1:
        return "ID Клиента";
    case 2:
        return "Дата занесения";
    case 3:
        return "Причина занесения";
    default:
        return QVariant();
    }
}
