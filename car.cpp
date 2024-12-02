#include "car.h"

Car::Car(int id, QString number, QString brand, QString color, bool availability)
    : id(id), number(number), brand(brand), color(color), availability(availability) {}

int Car::getId() const {
    return id;
}

QString Car::getNumber() const {
    return number;
}

QString Car::getBrand() const {
    return brand;
}

QString Car::getColor() const {
    return color;
}

bool Car::getAvailability() const {
    return availability;
}

void Car::setId(int id) {
    this->id = id;
}

void Car::setNumber(const QString &number) {
    this->number = number;
}

void Car::setBrand(const QString &brand) {
    this->brand = brand;
}

void Car::setColor(const QString &color) {
    this->color = color;
}

void Car::setAvailability(bool availability) {
    this->availability = availability;
}
