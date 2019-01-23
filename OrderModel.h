#pragma once

#include <list>
#include "DataModel.h"

class OrderModel {
public:
	OrderModel();
	OrderModel(const DataModel& model);
	~OrderModel();
	
	void add_model(const DataModel& model);
	size_t get_order_size();

private:
	std::list<DataModel> order_;
}