#include <iostream>
#include <sstream>
#include <iomanip>
#include "Protocol.h"

std::string Protocol::convert_to_string(uint32_t value, int size) {

	std::string result;
	std::stringstream buffer;
	buffer.fill('0');
	buffer << std::setw(size);
	buffer << value;
	result = buffer.str();

	return result;
}

std::string Protocol::convert_to_string(double value, int integer_size, int fractional_size) {
	std::string result;

	uint32_t integer = (uint16_t) value;

	if (integer_size > 0) {
		std::stringstream buffer_i;
		buffer_i.fill('0');
		buffer_i << std::setw(integer_size);
		buffer_i << integer;
		result = buffer_i.str();
	}

	if (fractional_size > 0) {
		int pow = 1;
		for (int i = 1; i <= fractional_size; i++) {
			pow *= 10;
		}	

		uint32_t fractional = (value*pow - integer*pow);
		std::stringstream buffer_f;
		buffer_f << fractional;
		result += buffer_f.str();		
	}

	while (result.size() < integer_size + fractional_size) {
		result += '0';
	}
	return result;
}