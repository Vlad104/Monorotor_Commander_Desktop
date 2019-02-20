#include "Keeper.h"

void Keeper::save(OrderModel& order) {
	std::ofstream file;
	file.open(path, std::ofstream::out | std::ofstream::trunc);

	int size = order.size();
	file << size << std::endl;
	for (auto& model : order) {
		file << model.get_dozators() << std::endl;
		file << model.get_volume() << std::endl;
		file << model.get_feedrate() << std::endl;
		file << model.get_accel() << std::endl;
		file << model.get_gear_A() << std::endl;
		file << model.get_gear_B() << std::endl;
		file << model.get_ratio_A() << std::endl;
		file << model.get_ratio_B() << std::endl;
	}

	file.close();
}

void Keeper::load(OrderModel& order) {
	std::ifstream file;
	file.open(path);
	int size;
	char dozators;		// dozators mode
	uint32_t volume;	// ul
	uint32_t feedrate;	// ul/min
	uint32_t accel;		// ul/(min*sec)
	double gear_A;		// pulses count / ml
	double gear_B;		// pulses count / ml
	double ratio_A;		// volume_A / (volume)
	double ratio_B;		// volume_B / (volume)

	order.clear();

	file >> size;
	for (int i = 0; i < size; i++) {
		file >> dozators;
		file >> volume;	
		file >> feedrate;	
		file >> accel;
		file >> gear_A;
		file >> gear_B;
		file >> ratio_A;
		file >> ratio_B;
		order.emplace_back(DataModel(dozators, volume, feedrate, accel, gear_A, gear_B, ratio_A, ratio_B));
	}

	file.close();
}
