#ifndef KEEPER_H
#define KEEPER_H

#include <fstream>
#include <string>
#include "OrderModel.h"

const std::string path = "settings.txt";

class Keeper {
public:
	Keeper() = default;
	~Keeper() = default;
	static void save(OrderModel& order);
	static void load(OrderModel& order);
private:

};

#endif // KEEPER_H