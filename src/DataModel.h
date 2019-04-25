#ifndef DATA_MODEL_H
#define DATA_MODEL_H

#include <string>

class DataModel {
public:
	DataModel();
	DataModel(char dozators, double volume, double feedrate, double accel, 
			double gear_A, double gear_B, double ratio_A, double ratio_B);
	~DataModel();

	char get_dozators() const;
	double get_volume() const;
	double get_feedrate() const;
	double get_accel() const;
	double get_gear_A() const;
	double get_gear_B() const;
	double get_ratio_A() const;
	double get_ratio_B() const;
	double get_ratio() const;

	void set_dozators(char dozators);
	void set_volume(double volume);
	void set_feedrate(double feedrate);
	void set_accel(double accel);
	void set_gear_A(double gear_A);
	void set_gear_B(double gear_B);
	void set_ratio_A(double ratio_A);
	void set_ratio_B(double ratio_B);

    void clear();

private:
	char dozators_;		// dozators mode
	double volume_;		// ul
	double feedrate_;	// ul/min
	double accel_;		// ul/(min*sec)
	double gear_A_;		// pulses count / ml
	double gear_B_;		// pulses count / ml
	double ratio_A_;	// volume_A / (volume)
	double ratio_B_;	// volume_B / (volume)
};

#endif // DATA_MODEL_H
