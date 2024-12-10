#ifndef BLACKLISTVIEW_H
#define BLACKLISTVIEW_H

#include <QAbstractTableModel>
#include <QList>
#include "blacklist.h"

class BlacklistView : public QAbstractTableModel {
private:

public:
    QList<Blacklist*> blacklists;
    BlacklistView(QObject *parent = nullptr);

    void addBlacklist(Blacklist *blacklist);
    bool removeBlacklist(int row);

    Blacklist* getBlacklist(int row) const;
    Blacklist *findBlacklistById(int id) const;
    Blacklist *findBlacklistByIdClient(int id) const;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
};

#endif // BLACKLISTVIEW_H
