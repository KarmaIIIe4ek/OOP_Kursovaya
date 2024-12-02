#include "clientview.h"

ClientView::ClientView(QObject *parent) : QAbstractTableModel(parent) {}

void ClientView::addClient(Client *Client) {
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    clients.append(Client);
    endInsertRows();
}

bool ClientView::removeClient(int row, QList<Rent*> rents) {
    Client *temp = clients.takeAt(row);
    for (int i = 0; i < rents.size(); i++) {
        Rent* element = rents.at(i);
        if (element->getClientId() == temp->getId()) {
            this->addClient(temp);
            int allRow = this->rowCount();
            if (allRow > 0) {
                this->removeRows(allRow - 1, 1, QModelIndex()); // Удаляем последнюю строку
                this->layoutChanged(); // Уведомляем представление об изменении данных
            }
            return false;
        }
    }
    beginRemoveRows(QModelIndex(), row, row);
    delete temp;
    endRemoveRows();
    return true;
}

int ClientView::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return clients.length();
}

int ClientView::columnCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return 5;
}

QVariant ClientView::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || role != Qt::DisplayRole) {
        return QVariant();
    }

    const Client *client = clients.at(index.row());

    switch (index.column()) {
    case 0:
        return client->getId();
    case 1:
        return client->getLastName();
    case 2:
        return client->getFirstName();
    case 3:
        return client->getNumberCL();
    case 4:
        return client->getPhone();
    default:
        return QVariant();
    }
}

Client* ClientView::getClient(int row) const {
    if (row < 0 || row >= clients.count()) {
        return nullptr;
    }
    return clients.at(row);
}

Client *ClientView::findClientById(int id) const {
    for (const Client *client : clients) {
        if (client->getId() == id) {
            return const_cast<Client *>(client);
        }
    }
    return nullptr;
}


QVariant ClientView::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole || orientation != Qt::Horizontal) {
        return QVariant();
    }
    switch (section) {
    case 0:
        return "ID";
    case 1:
        return "Фамилия";
    case 2:
        return "Имя";
    case 3:
        return "Номер ВУ";
    case 4:
        return "Телефон";
    default:
        return QVariant();
    }
}
