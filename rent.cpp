#include "rent.h"

Rent::Rent(int id, int clientId, int carId, const QDate &startRent, const QDate &endRent)
    : id(id), clientId(clientId), carId(carId), startRent(startRent), endRent(endRent) {}

int Rent::getId() const {
    return id;
}

int Rent::getClientId() const {
    return clientId;
}

int Rent::getCarId() const {
    return carId;
}

QDate Rent::getStartRent() const {
    return startRent;
}

QDate Rent::getEndRent() const {
    return endRent;
}

void Rent::setId(int id){
    this->id = id;
}

void Rent::setClientId(int clientId) {
    this->clientId = clientId;
}

void Rent::setCarId(int carId) {
    this->carId = carId;
}

void Rent::setStartRent(const QDate &startRent) {
    this->startRent = startRent;
}

void Rent::setEndRent(const QDate &endRent) {
    this->endRent = endRent;
}
