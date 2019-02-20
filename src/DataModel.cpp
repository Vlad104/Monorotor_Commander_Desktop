#include "DataModel.h"

DataModel::DataModel() :
	dozators_('2'),
	volume_(0.0), 
	feedrate_(0.0),
	accel_(20),
	gear_A_(1.0),
	gear_B_(1.0),
	ratio_A_(1.0),
	ratio_B_(1.0)
{}

DataModel::DataModel(char dozators, double volume, double feedrate, double accel, 
					double gear_A, double gear_B, double ratio_A, double ratio_B) :
	dozators_(dozators),
	volume_(volume), 
	feedrate_(feedrate),
	accel_(accel),
	gear_A_(gear_A),
	gear_B_(gear_B),
	ratio_A_(ratio_A),
	ratio_B_(ratio_B)
{}

DataModel::~DataModel() {}

char DataModel::get_dozators() const {
	return dozators_;
}

double DataModel::get_volume() const {
	return volume_;
}

double DataModel::get_feedrate() const {
	return feedrate_;
}

double DataModel::get_accel() const {
	return accel_;
}

double DataModel::get_gear_A() const {
	return gear_A_;
}

double DataModel::get_gear_B() const {
	return gear_B_;
}

double DataModel::get_ratio_A() const {
	return ratio_A_;
}

double DataModel::get_ratio_B() const {
	return ratio_B_;
}

double DataModel::get_ratio() const {
	return ratio_A_ / (ratio_A_ + ratio_B_);
}

void DataModel::set_dozators(char dozators) {
	dozators_ = dozators;
}

void DataModel::set_volume(double volume) {
	volume_ = volume;
}

void DataModel::set_feedrate(double feedrate) {
	feedrate_ = feedrate;
}

void DataModel::set_accel(double accel) {
	accel_ = accel;
}

void DataModel::set_gear_A(double gear_A) {
	gear_A_ = gear_A;
}

void DataModel::set_gear_B(double gear_B) {
	gear_B_ = gear_B;
}

void DataModel::set_ratio_A(double ratio_A) {
	ratio_A_ = ratio_A;
}

void DataModel::set_ratio_B(double ratio_B) {
	ratio_B_ = ratio_B;
}