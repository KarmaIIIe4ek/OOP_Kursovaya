#ifndef BLACKLIST_H
#define BLACKLIST_H

#include <QString>

class Blacklist {
private:
    int id;
    int idClient;
    QString date;
    QString reason;

public:
    Blacklist(int id, int idClient, QString date, QString reason);


    int getId() const;
    int getIdClient() const;
    QString getDate() const;
    QString getReason() const;

    void setId(int id);
    void setIdClient(int idClient);
    void setDate(const QString &brand);
    void setReason(const QString &Reason);
};

#endif // BLACKLIST_H
