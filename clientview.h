#ifndef CLIENTVIEW_H
#define CLIENTVIEW_H

#include <QAbstractTableModel>
#include <QList>
#include <QMessageBox>
#include "client.h"
#include "rent.h"

class ClientView : public QAbstractTableModel {
private:

public:
    QList<Client*> clients;
    ClientView(QObject *parent = nullptr);

    void addClient(Client *client);
    bool removeClient(int row, QList<Rent*> rents);

    Client* getClient(int row) const;
    Client *findClientById(int id) const;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
};
#endif // CLIENTVIEW_H
