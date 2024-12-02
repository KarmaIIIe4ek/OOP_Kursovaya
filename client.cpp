#include "client.h"

Client::Client(int id, QString lastName, QString firstName, QString numberCL, QString phone)
    : id(id), lastName(lastName), firstName(firstName), numberCL(numberCL), phone(phone) {}

int Client::getId() const {
    return id;
}

QString Client::getLastName() const {
    return lastName;
}

QString Client::getFirstName() const {
    return firstName;
}

QString Client::getNumberCL() const {
    return numberCL;
}

QString Client::getPhone() const {
    return phone;
}

void Client::setId(int id) {
    this->id = id;
}

void Client::setLastName(const QString &lastName) {
    this->lastName = lastName;
}

void Client::setFirstName(const QString &firstName) {
    this->firstName = firstName;
}

void Client::setNumberCL(const QString &numberCL) {
    this->numberCL = numberCL;
}

void Client::setPhone(const QString &phone) {
    this->phone = phone;
}
