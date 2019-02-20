#ifndef TRANSMIT_CONTROLLER_H
#define TRANSMIT_CONTROLLER_H

#include <queue>
#include <string>
#include "OrderModel.h"
#include "DataModel.h"
#include "Protocol.h"

class TransmitController {
public:
	TransmitController() = default;
	~TransmitController() = default;

	bool is_empty();
	std::string get_command();

	void get_stop();
	void get_start(const OrderModel& order);
	void get_continues(const OrderModel& order);

private:
	std::queue<std::string>	transmit_order_;
	OrderModel				order_;
	DataModel				prev_model_;

	void make_transmit_order(const OrderModel& order);
	void add_transmit_data(const DataModel& model);
	void clear_transmit_order();
};

#endif // TRANSMIT_CONTROLLER_H
