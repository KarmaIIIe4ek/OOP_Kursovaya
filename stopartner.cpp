#include "stopartner.h"

STOPartner::STOPartner(int id, QString address, QString number, QString dateStart, QString dateFinal)
    : id(id), address(address), number(number), dateStart(dateStart), dateFinal(dateFinal) {}

int STOPartner::getId() const {
    return id;
}

QString STOPartner::getAddress() const {
    return address;
}

QString STOPartner::getNumber() const {
    return number;
}

QString STOPartner::getDateStart() const {
    return dateStart;
}

QString STOPartner::getDateFinal() const {
    return dateFinal;
}

void STOPartner::setId(int id) {
    this->id = id;
}

void STOPartner::setAddress(const QString &address) {
    this->address = address;
}

void STOPartner::setNumber(const QString &number) {
    this->number = number;
}

void STOPartner::setDateStart(const QString &dateStart) {
    this->dateStart = dateStart;
}

void STOPartner::setDateFinal(const QString &dateFinal) {
    this->dateFinal = dateFinal;
}
