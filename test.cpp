#include <iostream>
#include "DataModel.h"
#include "TransmitController.h"

#include "OrderModel.h"

int main() {
	std::cout << "START" << std::endl;

	OrderModel order;
	order.emplace_back(DataModel('0', 111000, 222000, 33000, 99, 4444, 5555, 1, 1, false));
	order.emplace_back(DataModel('1', 123456, 999999, 1000, 50, 4444, 5555, 1, 2, true));
	order.emplace_back(DataModel('2', 999999, 1000, 123456, 1, 4444, 5555, 2, 1, false));
	order.emplace_back(DataModel('2', 2000, 22000, 2010, 75, 4444, 5555, 100, 1, true));
	order.emplace_back(DataModel('2', 2000, 22000, 2010, 75, 4444, 5555, 100, 1, true));
	order.emplace_back(DataModel('2', 2000, 22000, 2010, 75, 4444, 5555, 100, 1, false));

	TransmitController ctrl(order);
	while (!ctrl.is_empty()) {
		std::cout << ctrl.get_command() << std::endl;
	}

	return 0;
}