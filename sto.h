#ifndef STO_H
#define STO_H

#include <QString>
class STOPartner
{
private:
    int id;
    QString address;
    QString number;
    QString dateStart;
    QString dateFinal;
};

class STOPartner {
private:
    int id;
    QString address;
    QString number;
    QString dateStart;
    QString dateFinal;

public:
    Sto(int id, QString number, QString brand, QString color, bool avai);


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

#endif // STO_H

