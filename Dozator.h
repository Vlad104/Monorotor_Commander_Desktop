#pragma once

//typedef int uint8_t;

class Dozator {
public:
	Dozator();
	~Dozator() {};

	void set_volume(double volume);
	void set_feedrate(double feedrate);
	void set_accel(double accel);
	void set_step_mode(int step_mode);
	void set_gear_ratio(double gear_ratio);

	double get_volume() const;
	double get_feedrate() const;
	double get_accel() const;
	double get_ratio() const;

private:
	double volume_;		// ml
	double feedrate_;	// g/sec
	double accel_;		// g/sec^2

	int step_mode_;		// ml_to_steps
	double gear_ratio_; 	// ml_to_steps
	double ratio_;			// ml_to_impulses
};