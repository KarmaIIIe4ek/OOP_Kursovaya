#ifndef CARVIEW_H
#define CARVIEW_H

#include <QAbstractTableModel>
#include <QList>
#include "car.h"
#include "rent.h"

class CarView : public QAbstractTableModel {
private:

public:
    QList<Car*> cars;
    CarView(QObject *parent = nullptr);

    void addCar(Car *car);
    bool removeCar(int row, QList<Rent*> rents);
    int changeAvailability(int id);

    Car* getCar(int row) const;
    Car *findCarById(int id) const;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
};
#endif // CARVIEW_H
