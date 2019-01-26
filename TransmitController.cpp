#include "TransmitController.h"

TransmitController::TransmitController() : prev_parameters("") {
	make_transmit_data();
}

TransmitController::TransmitController(const OrderModel& order) : order_(order), prev_parameters("") {
	make_transmit_data();
}

bool TransmitController::is_empty() {
	return transmit_data_.empty();
}

std::string TransmitController::get_command() {
	std::string command = transmit_data_.front();
	transmit_data_.pop();
	return command;
}

void TransmitController::make_transmit_data() {
	for (auto& model : order_) {
		prepare_model(model);
	}
}

void TransmitController::prepare_model(DataModel& model) {

	ParametersProtocol params(model);
	std::string parameters = params.get_command();
	if (parameters != prev_parameters) {
		transmit_data_.push(parameters);
		prev_parameters = parameters;
	}

	ActionProtocol act('0', '1');
	transmit_data_.push(act.get_command());
	
}