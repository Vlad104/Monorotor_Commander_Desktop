#pragma once

class Command {
public:
	Command();
	~Command() {};

	void set_mass(double mass);
	void set_volume(double volume);
	void set_density(double density);
	void set_feedrate(double feedrate);
	void set_accel(double accel);

	double get_mass() const;
	double get_volume() const;
	double get_density() const;
	double get_feedrate() const;
	double get_accel() const;

private:
	double mass_;		// g
	double volume_;		// ml
	double density_;    // g/ml
	double feedrate_;	// g/sec
	double accel_;		// g/sec^2
};