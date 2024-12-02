#include "carview.h"

CarView::CarView(QObject *parent) : QAbstractTableModel(parent) {}

void CarView::addCar(Car *car) {
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    cars.append(car);
    endInsertRows();
}

bool CarView::removeCar(int row, QList<Rent*> rents) {
    Car *temp = cars.takeAt(row);
    for (int i = 0; i < rents.size(); i++) {
        Rent* element = rents.at(i);
        if (element->getCarId() == temp->getId()) {
            this->addCar(temp);
            int allRow = this->rowCount();
            if (allRow > 0) {
                this->removeRows(allRow - 1, 1, QModelIndex());
                this->layoutChanged();
            }
            return false;
        }
    }
    beginRemoveRows(QModelIndex(), row, row);
    delete temp;
    endRemoveRows();
    return true;
}

int CarView::changeAvailability(int id){
    int index = 0;
    for (Car *car : cars) {
        if (car->getId() == id) {
            return index;
        }
        index++;
    }
}

int CarView::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return cars.count();
}

int CarView::columnCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return 5;
}

QVariant CarView::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || role != Qt::DisplayRole) {
        return QVariant();
    }

    const Car *car = cars.at(index.row());

    switch (index.column()) {
    case 0:
        return car->getId();
    case 1:
        return car->getNumber();
    case 2:
        return car->getBrand();
    case 3:
        return car->getColor();
    case 4:
        return car->getAvailability();
    default:
        return QVariant();
    }
}

Car* CarView::getCar(int row) const {
    if (row < 0 || row >= cars.count()) {
        return nullptr;
    }
    return cars.at(row);
}

Car *CarView::findCarById(int id) const {
    for (const Car *car : cars) {
        if (car->getId() == id) {
            return const_cast<Car *>(car);
        }
    }
    return nullptr;
}

QVariant CarView::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole || orientation != Qt::Horizontal) {
        return QVariant();
    }

    switch (section) {
    case 0:
        return "ID Автомобиля";
    case 1:
        return "Номер";
    case 2:
        return "Марка";
    case 3:
        return "Цвет";
    case 4:
        return "В наличии";
    default:
        return QVariant();
    }
}
