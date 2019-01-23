#include "OrderModel.h"

OrderModel::OrderModel() {}

OrderModel::OrderModel(const DataModel& model) : order_(1, model) {}

OrderModel::~OrderModel() {}

void OrderModel::add_model(const DataModel& model) {
	order_.emplace_back(model);
}

size_t OrderModel::get_order_size() {
	return order_.size();
}