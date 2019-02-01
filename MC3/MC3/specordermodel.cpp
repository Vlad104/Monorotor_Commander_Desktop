#include "specordermodel.h"

SpecOrderModel::SpecOrderModel(OrderModel& order)
{

    QStringList horizontalHeader {"Дозатор", "Объём", "Подача", "A:B", "Реверс"};
    this->setHorizontalHeaderLabels(horizontalHeader);

    for (auto& data_model : order) {
        QList<QStandardItem*> row;
        item_ = new QStandardItem();
        item_->setTextAlignment(Qt::AlignCenter);
        item_->setText(QChar(data_model.get_dozators()));
        row.append(item_);
        item_ = new QStandardItem();
        item_->setTextAlignment(Qt::AlignCenter);
        item_->setText(QString::number(data_model.get_volume()));
        row.append(item_);
        item_ = new QStandardItem();
        item_->setTextAlignment(Qt::AlignCenter);
        item_->setText(QString::number(data_model.get_feedrate()));
        row.append(item_);
        item_ = new QStandardItem();
        item_->setTextAlignment(Qt::AlignCenter);
        QString ratio = QString::number(data_model.get_ratio_A()) + " : " + QString::number(data_model.get_ratio_B());
        item_->setText(ratio);
        row.append(item_);
        item_ = new QStandardItem();
        item_->setTextAlignment(Qt::AlignCenter);
        item_->setText(QString::number(data_model.get_reverse()));
        row.append(item_);
        this->appendRow(row);
    }
}

SpecOrderModel::~SpecOrderModel() {

}
