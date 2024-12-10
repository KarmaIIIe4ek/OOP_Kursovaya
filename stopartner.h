#ifndef STOPARTNER_H
#define STOPARTNER_H

#include <QString>

class STOPartner
{
private:
    int id;
    QString address;
    QString number;
    QString dateStart;
    QString dateFinal;
public:
    STOPartner(int id, QString address, QString number, QString dateStart, QString dateFinal);


    int getId() const;
    QString getAddress() const;
    QString getNumber() const;
    QString getDateStart() const;
    QString getDateFinal() const;

    void setId(int id);
    void setAddress(const QString &address);
    void setNumber(const QString &number);
    void setDateStart(const QString &dateStart);
    void setDateFinal(const QString &dateFinal);
};


#endif // STOPARTNER_H
