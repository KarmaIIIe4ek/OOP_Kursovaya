#ifndef CAR_H
#define CAR_H

#include <QString>

class Car {
private:
    int id;
    QString number;
    QString brand;
    QString color;
    bool availability;

public:

    Car(int id, QString number, QString brand, QString color, bool availability);

    int getId() const;
    QString getNumber() const;
    QString getBrand() const;
    QString getColor() const;
    bool getAvailability() const;

    void setId(int id);
    void setNumber(const QString &number);
    void setBrand(const QString &brand);
    void setColor(const QString &color);
    void setAvailability(bool availability);
};

#endif // CAR_H
