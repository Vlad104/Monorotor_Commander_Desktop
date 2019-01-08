#include "Command.h"

Command::Command() :
	mass_(0), volume_(0), density_(1), feedrate_(0), accel_(0)
{}

void Command::set_mass(double mass) {
	mass_ = mass;
}

void Command::set_volume(double volume) {
	volume_ = volume;
}

void Command::set_density(double density) {
	density_ = density;
}

void Command::set_feedrate(double feedrate) {
	feedrate_ = feedrate;
}

void Command::set_accel(double accel) {
	accel_ = accel;
}

double Command::get_mass() const {
	return mass_;
}

double Command::get_volume() const {
	return volume_;
}

double Command::get_density() const {
	return density_;
}

double Command::get_feedrate() const {
	return feedrate_;
}

double Command::get_accel() const {
	return accel_;
}