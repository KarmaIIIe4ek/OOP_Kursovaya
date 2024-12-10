#ifndef STOPARTNERVIEW_H
#define STOPARTNERVIEW_H

#include <QAbstractTableModel>
#include <QList>
#include "stopartner.h"

class STOPartnerView : public QAbstractTableModel {
private:

public:
    QList<STOPartner*> stoPartners;
    STOPartnerView(QObject *parent = nullptr);

    void addSTOPartner(STOPartner *stopartner);
    void removeSTOPartner(int row);

    STOPartner* getSTOPartner(int row) const;
    STOPartner *findSTOPartnerById(int id) const;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
};

#endif // STOPARTNERVIEW_H
