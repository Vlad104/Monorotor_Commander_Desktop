#include "DataModel.h"

DataModel::DataModel() :
	volume_(0.0), 
	feedrate_(0.0),
	accel_(0.3333),
	reverse_(0.0),
	gear_A_(1.0),
	gear_B_(1.0),
	ratio_A_(1.0),
	ratio_B_(1.0),
	direction_(true)
{}

DataModel::DataModel(uint16_t volume, uint16_t feedrate, uint16_t accel, uint16_t reverse,
					uint16_t gear_A, uint16_t gear_B, uint16_t ratio_A, uint16_t ratio_B,
					bool direction) :
	volume_(0.0), 
	feedrate_(0.0),
	accel_(0.3333),
	reverse_(0.0),
	gear_A_(1.0),
	gear_B_(1.0),
	ratio_A_(1.0),
	ratio_B_(1.0),
	direction_(true)
{}

DataModel::~DataModel() {}

char DataModel::get_dozators() {
	return dozators_;
}

uint16_t DataModel::get_volume() {
	return volume_;
}

uint16_t DataModel::get_feedrate() {
	return feedrate_;
}

uint16_t DataModel::get_accel() {
	return accel_;
}

uint16_t DataModel::get_reverse() {
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

void DataModel::set_volume(uint16_t volume) {
	volume_ = volume;
}

void DataModel::set_feedrate(uint16_t feedrate) {
	feedrate_ = feedrate;
}

void DataModel::set_accel(uint16_t accel) {
	accel_ = accel;
}

void DataModel::set_reverse(uint16_t reverse) {
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