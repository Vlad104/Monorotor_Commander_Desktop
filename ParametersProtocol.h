#pragma once
#include "Protocol.h"
#include "DataModel.h"

const char volume_size = 4;
const char feedrate_size = 3;
const char ratio_size = 3;
const char reverse_size = 3;

class ParametersProtocol : public Protocol {
public:
	ParametersProtocol();	
	ParametersProtocol(char dozators, uint32_t volume, uint32_t feedrate, double ratio, uint32_t reverse);
	ParametersProtocol(DataModel& model); 

	////////////////////////////////////////////
	~ParametersProtocol() = default;
	std::string get_command();

private:
	const char id_ = '@';
	char dozators_;
	uint32_t volume_;
	uint32_t feedrate_;
	double ratio_;
	uint32_t reverse_;

	std::string str_volume_;
	std::string str_feedrate_;
	std::string str_ratio_;
	std::string str_reverse_;

	void make_conversion();
	std::string make_command();
};