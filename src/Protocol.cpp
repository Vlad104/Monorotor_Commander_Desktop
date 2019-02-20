#include "Protocol.h"


std::string Protocol::make_dozators(char dozators) {
	std::string str_dozators(1, dozators);
	return "@D" + str_dozators + "*";
}

std::string Protocol::make_volume(double volume) {
	std::string str_value = convert_to_string(volume);
	return "@V" + str_value + "*";
}

std::string Protocol::make_feedrate(double feedrate) {
	std::string str_value = convert_to_string(feedrate);
	return "@F" + str_value + "*";
}

std::string Protocol::make_accel(double accel) {
	std::string str_value = convert_to_string(accel);
	return "@A" + str_value + "*";
}

std::string Protocol::make_gear_A(double gear_A) {
	std::string str_value = convert_to_string(gear_A);
	return "@a" + str_value + "*";
}

std::string Protocol::make_gear_B(double gear_B) {
	std::string str_value = convert_to_string(gear_B);
	return "@b" + str_value + "*";
}

std::string Protocol::make_ratio(double ratio) {
	std::string str_value = convert_to_string(ratio);
	return "@R" + str_value + "*";
}

std::string Protocol::convert_to_string(double value) {
	std::stringstream buffer;
	buffer << value;
	return buffer.str();
}

std::string Protocol::make_start() {
	return "=1";
}

std::string Protocol::make_stop() {
	return "=0";
}

std::string Protocol::make_continues() {
	return "=2";
}