#ifndef RENTVIEW_H
#define RENTVIEW_H
#include <QAbstractTableModel>
#include <QList>
#include "rent.h"

class RentView : public QAbstractTableModel {
private:

public:
    QList<Rent*> rents;
    RentView(QObject *parent = nullptr);

    void addRent(Rent *rent);
    void removeRent(int row);

    Rent* getRent(int row) const;
    Rent *findRentById(int id) const;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
};

#endif // RENTVIEW_H
