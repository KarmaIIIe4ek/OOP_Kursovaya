#ifndef CLIENT_H
#define CLIENT_H

#include <QString>

class Client
{
private:
    int id;
    QString lastName;
    QString firstName;
    QString numberCL;
    QString phone;
public:
    Client(int id, QString lastName, QString firstName, QString numberCL, QString phone);

    int getId() const;
    QString getLastName() const;
    QString getFirstName() const;
    QString getNumberCL() const;
    QString getPhone() const;

    void setId(int id);
    void setLastName(const QString &lastName);
    void setFirstName(const QString &firstName);
    void setNumberCL(const QString &numberCL);
    void setPhone(const QString &phone);
};
#endif // CLIENT_H
