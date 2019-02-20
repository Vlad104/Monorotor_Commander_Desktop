#include <iostream>
#include "DataModel.h"
#include "TransmitController.h"
#include "Keeper.h"

#include "OrderModel.h"

int main() {
	std::cout << "START" << std::endl;

	OrderModel order;

/*
	order.emplace_back(DataModel('0', 111000, 221000, 33000, 4444, 5555, 1, 1));
	order.emplace_back(DataModel('0', 112000, 223000, 33000, 4444, 5555, 1, 2));
	order.emplace_back(DataModel('0', 113000, 224000, 33000, 4444, 5555, 1, 1));
	order.emplace_back(DataModel('0', 114000, 226000, 33000, 4444, 5555, 1, 1));
	order.emplace_back(DataModel('0', 115000, 222000, 33000, 4444, 5555, 1, 1));
	order.emplace_back(DataModel('0', 116000, 222000, 33000, 4444, 5555, 1, 1));
*/
	Keeper::load(order);

	TransmitController ctrl;
	ctrl.get_start(order);
	while (!ctrl.is_empty()) {
		std::cout << ctrl.get_command() << std::endl;
	}

	Keeper::save(order);

	return 0;
}