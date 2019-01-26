#include "DataModel.h"

DataModel::DataModel() :
	dozators_('2'),
	volume_(0.0), 
	feedrate_(0.0),
	accel_(20),
	reverse_(0.0),
	gear_A_(1.0),
	gear_B_(1.0),
	ratio_A_(1.0),
	ratio_B_(1.0),
	direction_(true)
{}

DataModel::DataModel(char dozators, uint32_t volume, uint32_t feedrate, uint32_t accel, 
					uint32_t reverse, double gear_A, double gear_B, double ratio_A,
					double ratio_B, bool direction) :
	dozators_(dozators),
	volume_(volume), 
	feedrate_(feedrate),
	accel_(accel),
	reverse_(reverse),
	gear_A_(gear_A),
	gear_B_(gear_B),
	ratio_A_(ratio_A),
	ratio_B_(ratio_B),
	direction_(direction)
{}

/*
DataModel::DataModel(const DataModel& other) :
	dozators_(other.dozators_),
	volume_(other.volume_), 
	feedrate_(other.feedrate_),
	accel_(other.accel_),
	reverse_(other.reverse_),
	gear_A_(other.gear_A_),
	gear_B_(other.gear_B_),
	ratio_A_(other.ratio_A_),
	ratio_B_(other.ratio_B_),
	direction_(other.direction_)
{}
*/
/*
DataModel::DataModell(DataModel&& other) :
	dozators_(other.dozators),
	volume_(other.volume), 
	feedrate_(other.feedrate),
	accel_(other.accel),
	reverse_(other.reverse),
	gear_A_(other.gear_A),
	gear_B_(other.gear_B),
	ratio_A_(other.ratio_A),
	ratio_B_(other.ratio_B),
	direction_(other.direction)
{}
*/

DataModel::~DataModel() {}

char DataModel::get_dozators() {
	return dozators_;
}

uint32_t DataModel::get_volume() {
	return volume_;
}

uint32_t DataModel::get_feedrate() {
	return feedrate_;
}

uint32_t DataModel::get_accel() {
	return accel_;
}

uint32_t DataModel::get_reverse() {
	return reverse_;
}

double DataModel::get_gear_A() {
	return gear_A_;
}

double DataModel::get_gear_B() {
	return gear_B_;
}

double DataModel::get_ratio_A() {
	return ratio_A_;
}

double DataModel::get_ratio_B() {
	return ratio_B_;
}

double DataModel::get_ratio() {
	return ratio_A_ / (ratio_A_ + ratio_B_);
}

bool DataModel::get_direction() {
	return direction_;
}


void DataModel::set_dozators(char dozators) {
	dozators_ =dozators;
}

void DataModel::set_volume(uint32_t volume) {
	volume_ = volume;
}

void DataModel::set_feedrate(uint32_t feedrate) {
	feedrate_ = feedrate;
}

void DataModel::set_accel(uint32_t accel) {
	accel_ = accel;
}

void DataModel::set_reverse(uint32_t reverse) {
	reverse_ = reverse;
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

void DataModel::set_direction(bool direction) {
	direction_ = direction;
}

bool DataModel::change_direction() {
	direction_ = !direction_;
	return direction_;
}

void DataModel::print(std::ostream& out) {
	out << get_dozators() << std::endl;
	out << get_volume() << std::endl;
	out << get_feedrate() << std::endl;
	out << get_accel() << std::endl;
	out << get_reverse() << std::endl;
	out << get_gear_A() << std::endl;
	out << get_gear_B() << std::endl;
	out << get_ratio_A() << std::endl;
	out << get_ratio_B() << std::endl;
	out << get_ratio() << std::endl;
	out << get_direction() << std::endl;
} 