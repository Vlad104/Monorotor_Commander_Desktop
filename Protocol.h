#pragma once
#include <string>

class Protocol {
public:
	Protocol() = default;
	virtual ~Protocol() = default;
	virtual std::string get_command() = 0;

protected:
	std::string convert_to_string(uint32_t value, int size);
	std::string convert_to_string(double value, int int_size, int frac_size);
};

