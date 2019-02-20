#include "TransmitController.h"

bool TransmitController::is_empty() {
	return transmit_order_.empty();
}

void TransmitController::get_stop() {
	clear_transmit_order();
	transmit_order_.push(Protocol::make_stop());
}

void TransmitController::get_start(const OrderModel& order) {
	make_transmit_order(order);
	transmit_order_.push(Protocol::make_start());
}

void TransmitController::get_continues(const OrderModel& order) {
	make_transmit_order(order);
	transmit_order_.push(Protocol::make_continues());
}

std::string TransmitController::get_command() {
	std::string command = transmit_order_.front();
	transmit_order_.pop();
	return command;
}

void TransmitController::make_transmit_order(const OrderModel& order) {
	clear_transmit_order();
	for (const auto& model : order) {
		add_transmit_data(model);
	}
}

void TransmitController::add_transmit_data(const DataModel& model) {
	if (model.get_dozators() != prev_model_.get_dozators()) {
		prev_model_.set_dozators(model.get_dozators());
		transmit_order_.push(Protocol::make_dozators(model.get_dozators()));
	}
	if (model.get_volume() != prev_model_.get_volume()) {
		prev_model_.set_volume(model.get_volume());
		transmit_order_.push(Protocol::make_volume(model.get_volume()));
	}
	if (model.get_feedrate() != prev_model_.get_feedrate()) {
		prev_model_.set_feedrate(model.get_feedrate());
		transmit_order_.push(Protocol::make_feedrate(model.get_feedrate()));
	}
	if (model.get_accel() != prev_model_.get_accel()) {
		prev_model_.set_accel(model.get_accel());
		transmit_order_.push(Protocol::make_accel(model.get_accel()));
	}
	if (model.get_gear_A() != prev_model_.get_gear_A()) {
		prev_model_.set_gear_A(model.get_gear_A());
		transmit_order_.push(Protocol::make_gear_A(model.get_gear_A()));
	}
	if (model.get_gear_B() != prev_model_.get_gear_B()) {
		prev_model_.set_gear_B(model.get_gear_B());
		transmit_order_.push(Protocol::make_gear_B(model.get_gear_B()));
	}
	if (model.get_ratio() != prev_model_.get_ratio()) {
		prev_model_.set_ratio_A(model.get_ratio_A());
		prev_model_.set_ratio_B(model.get_ratio_B());
		transmit_order_.push(Protocol::make_ratio(model.get_ratio()));
	}
}

void TransmitController::clear_transmit_order() {
	while(!transmit_order_.empty()) {
		transmit_order_.pop();
	}
}