#include "TransmitController.h"

TransmitController::TransmitController(const OrderModel& order) : model_(order_) {}

TransmitController::~TransmitController() {}

bool TransmitController::is_empty() {
	return transmit_data_.empty();
}

std::string TransmitController::get_command() {
	std::string command = transmit_data_.front();
	transmit_data_.pop();
	return command;
}

void TransmitController::make_transmit_data() {
	for (const auto& model : order_) {
		prepare_model(model);
	}
}

void TransmitController::prepare_model(const DataModel& model) {
	ParametersProtocol parameters(model.get_dozator(), model.get_volume(), model.get_feedrate(), model.get_ratio(), model.get_reverse());
	std::string temp;
	parameters.get_command(temp);
	temp.clear();
	//// остальные команды

	transmit_data_.push(dadsaasd);
}