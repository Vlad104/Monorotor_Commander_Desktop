#pragma once

#include <queue>
#include <string>
#include "OrderModel.h"
#include "DataModel.h"

#include "ParametersProtocol.h"
#include "ActionProtocol.h"

class TransmitController {
public:
	TransmitController();
	TransmitController(const OrderModel& order_);
	~TransmitController() = default;

	bool is_empty();
	std::string get_command();

private:
	std::queue<std::string> transmit_data_;
	OrderModel order_;

	std::string prev_parameters;

	void make_transmit_data();
	void prepare_model(DataModel& model);
};