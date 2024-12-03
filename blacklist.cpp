#include "blacklist.h"

Blacklist::Blacklist(int id, int idClient, QString date, QString reason)
    : id(id), idClient(idClient), date(date), reason(reason) {}

int Blacklist::getId() const {
    return id;
}

int Blacklist::getIdClient() const {
    return idClient;
}

QString Blacklist::getDate() const {
    return date;
}

QString Blacklist::getReason() const {
    return reason;
}

void Blacklist::setId(int id) {
    this->id = id;
}

void Blacklist::setIdClient(int idClient) {
    this->idClient = idClient;
}

void Blacklist::setDate(const QString &date) {
    this->date = date;
}

void Blacklist::setReason(const QString &date) {
    this->reason = reason;
}
