#pragma once

#include <list>
#include "DataModel.h"

typedef std::list<DataModel> OrderModel;

/*
class OrderModel {
public:
	OrderModel();
	OrderModel(const DataModel& model);
	~OrderModel();
	
	void add_model(const DataModel& model);
	DataModel front_model();
	size_t get_order_size();

private:
	std::list<DataModel> order_;
};
*/