#pragma once

#include <string>

class DataModel {
public:
	DataModel();
	DataModel::DataModel(uint16_t volume, uint16_t feedrate, uint16_t accel, uint16_t reverse,
					uint16_t gear_A, uint16_t gear_B, uint16_t ratio_A, uint16_t ratio_B,
					bool direction);
	~DataModel();

	char get_dozators();
	uint16_t get_volume();
	uint16_t get_feedrate();
	uint16_t get_accel();
	uint16_t get_reverse();
	double get_gear_A();
	double get_gear_B();
	double get_ratio_A();
	double get_ratio_B();
	double get_ratio();
	bool get_direction();

	void set_dozetors(char dozators);
	void set_volume(uint16_t volume);
	void set_feedrate(uint16_t feedrate);
	void set_accel(uint16_t accel);
	void set_reverse(uint16_t reverse);
	void set_gear_A(double gear_A);
	void set_gear_B(double gear_B);
	void set_ratio_A(double ratio_A);
	void set_ratio_B(double ratio_B);
	void set_direction(bool direction);

	bool change_direction();

private:
	char dozators_;		// dozators mode
	uint16_t volume_;	// ul
	uint16_t feedrate_;	// ul/min
	uint16_t accel_;	// ul/min^2
	uint16_t reverse_;	// procents (previously - ul)
	double gear_A_;		// pulses count / ml
	double gear_B_;		// pulses count / ml
	double ratio_A_;	// volume_A / (volume)
	double ratio_B_;	// volume_B / (volume)
	bool direction_;	// 
}