#pragma once
#include <string>

struct Protocol {
	Protocol() {};
	virtual ~Protocol() {};
	virtual bool get_command(std::string& result) = 0;

	std::string convert_to_string(uint16_t value, int size);
	std::string convert_to_string(double value, int int_size, int frac_size);
};


std::string Protocol::convert_to_string(uint16_t value, int size) {
	std:string result;
	for (int i = 0; i < size; i++) {
		char temp = (char) (value % (size - i) + 48);
		result += temp;
	}

	return result;
}

std::string Protocol::convert_to_string(double value, int integer_size, int fractional_size) {
	std:string result;

	uint16_t integer = (uint16_t) value;
	uint16_t fractional = value - integer;

	for (int i = 0; i < integer_size; i++) {
		char temp = (char) (value % (size - i) + 48);
		result += temp;
	}

	for (int i = 0; i < fractional_size; i++) {
		char temp = (char) (value % (size - i) + 48);
		result += temp;
	}
	
	return result;
}