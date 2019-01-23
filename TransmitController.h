#pragma once

#include <queue>
#include <string>
#include "OrderModel.h"
#include "DataModel.h"

class TransmitController {
public:
	TransmitController(const OrderModel& order_);
	~TransmitController();

	bool is_empty();
	std::string get_command();

private:
	std::queue<std::string>> transmit_data_;
	OrderModel order_;

	void make_transmit_data();
	void prepare_model(const DataModel& model);
}