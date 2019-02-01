#ifndef SPECORDERMODEL_H
#define SPECORDERMODEL_H

#include <QStandardItemModel>
#include <QStandardItem>

#include "../../DataModel.h"
#include "../../OrderModel.h"

class SpecOrderModel : public QStandardItemModel
{
public:
    SpecOrderModel(OrderModel& order);
    ~SpecOrderModel();

private:
    QStandardItem* item_;
};

#endif // SPECORDERMODEL_H
