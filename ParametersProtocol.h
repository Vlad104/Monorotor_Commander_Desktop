#pragma once
#include "Protocol.h"

const char identificator = '@';
const char volume_size = 4;
const char feedrate_size = 3;
const char ratio_size = 3;
const char revers_size = 3;

class ParametersProtocol : public Protocol {
public:
	ParametersProtocol();	
	ParametersProtocol(char dozators, uint16_t volume, uint16_t feedrate, double ratio, uint16_t revers); // с домножением на 10 итд разобраться

	////////////////////////////////////////////
	~ParametersProtocol() {};
	bool get_command(std::string& result);

private:
	char dozators_;
	uint16_t volume_;
	uint16_t feedrate_;
	double ratio_;
	uint16_t revers_;

	std::string str_volume_;
	std::string str_feedrate_;
	std::string str_ratio_;
	std::string str_revers_;

	bool make_command(std::string& result);
};