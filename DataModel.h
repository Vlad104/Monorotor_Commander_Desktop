#pragma once

#include <ostream>
#include <string>

class DataModel {
public:
	DataModel();
	DataModel(char dozators, uint32_t volume, uint32_t feedrate, uint32_t accel, 
			uint32_t reverse, double gear_A, double gear_B, double ratio_A,
			double ratio_B, bool direction);
	//DataModel(const DataModel& other);
	//DataModel& operator=(const DataModel&);
	//DataModel(DataModel&& other);
	//DataModel& operator=(DataModel&&);
	~DataModel();

	char get_dozators();
	uint32_t get_volume();
	uint32_t get_feedrate();
	uint32_t get_accel();
	uint32_t get_reverse();
	double get_gear_A();
	double get_gear_B();
	double get_ratio_A();
	double get_ratio_B();
	double get_ratio();
	bool get_direction();

	void set_dozators(char dozators);
	void set_volume(uint32_t volume);
	void set_feedrate(uint32_t feedrate);
	void set_accel(uint32_t accel);
	void set_reverse(uint32_t reverse);
	void set_gear_A(double gear_A);
	void set_gear_B(double gear_B);
	void set_ratio_A(double ratio_A);
	void set_ratio_B(double ratio_B);
	void set_direction(bool direction);

	bool change_direction();
	void print(std::ostream& out);

private:
	char dozators_;		// dozators mode
	uint32_t volume_;	// ul
	uint32_t feedrate_;	// ul/min
	uint32_t accel_;	// ul/(min*sec)
	uint32_t reverse_;	// procents (previously - ul)
	double gear_A_;		// pulses count / ml
	double gear_B_;		// pulses count / ml
	double ratio_A_;	// volume_A / (volume)
	double ratio_B_;	// volume_B / (volume)
	bool direction_;	// 
};