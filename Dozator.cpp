#include "Dozator.h"

Dozator::Dozator() :
	volume_(0), feedrate_(0), accel_(0), step_mode_(1), gear_ratio_(1)
{
	ratio_ = gear_ratio_ * (double) step_mode_;
}

void Dozator::set_volume(double volume) {
	volume_ = volume;
}

void Dozator::set_feedrate(double feedrate) {
	feedrate_ = feedrate;
}

void Dozator::set_accel(double accel) {
	accel_ = accel;
}

void Dozator::set_step_mode(int step_mode) {
	step_mode_ = step_mode;
	ratio_ = gear_ratio_ * (double) step_mode_;
}

void Dozator::set_gear_ratio(double gear_ratio) {
	gear_ratio_ = gear_ratio;
	ratio_ = gear_ratio_ * (double) step_mode_;
}

double Dozator::get_volume() const {
	return volume_;
}

double Dozator::get_feedrate() const {
	return feedrate_;
}

double Dozator::get_accel() const {
	return accel_;
}

double Dozator::get_ratio() const {
	return ratio_;
}