#ifndef CUSTOMQUERYMODEL_H
#define CUSTOMQUERYMODEL_H

#include <QSqlQueryModel>
#include <QSqlQuery> 

class CustomQueryModel : public QSqlQueryModel {
    Q_OBJECT
public:
    explicit CustomQueryModel(QObject *parent = nullptr);

    QVariant data(const QModelIndex &index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
};

#endif // CUSTOMQUERYMODEL_H
