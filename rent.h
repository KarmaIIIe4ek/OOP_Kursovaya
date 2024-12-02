#ifndef RENT_H
#define RENT_H

#include <QDate>

class Rent {
private:
    int id;
    int clientId;
    int carId;
    QDate startRent;
    QDate endRent;

public:
    Rent(int id, int clientId, int carId, const QDate &startRent, const QDate &endRent);

    int getId() const;
    int getClientId() const;
    int getCarId() const;
    QDate getStartRent() const;
    QDate getEndRent() const;

    void setId(int id);
    void setClientId(int clientId);
    void setCarId(int carId);
    void setStartRent(const QDate &startRent);
    void setEndRent(const QDate &endRent);
};


#endif // RENT_H
