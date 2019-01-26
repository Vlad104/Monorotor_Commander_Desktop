#include "ParametersProtocol.h"

ParametersProtocol::ParametersProtocol() : 
	dozators_('2'), volume_(0), feedrate_(0), ratio_(0.5), reverse_(0)
{}


ParametersProtocol::ParametersProtocol(char dozators, uint32_t volume, uint32_t feedrate, double ratio, uint32_t reverse) :
	dozators_(dozators), volume_(volume), feedrate_(feedrate), ratio_(ratio), reverse_(reverse)
{}

ParametersProtocol::ParametersProtocol(DataModel& model) :
	dozators_(model.get_dozators()), volume_(model.get_volume()), feedrate_(model.get_feedrate()),
	ratio_(model.get_ratio()), reverse_(model.get_reverse())
{}

std::string ParametersProtocol::get_command() {
	return make_command();
}

void ParametersProtocol::make_conversion() {	
	volume_ /= 100;		// ul -> ml and then x10
	feedrate_ /= 1000;	// ul/min -> ml/min;
	reverse_ *= 10;		// (procents) x10
}

std::string ParametersProtocol::make_command() {
	std::string result;

	make_conversion();

	str_volume_ = convert_to_string(volume_, volume_size);
	str_feedrate_ = convert_to_string(feedrate_, feedrate_size);
	str_ratio_ = convert_to_string(ratio_, 0, ratio_size);
	str_reverse_ = convert_to_string(reverse_, reverse_size);

	result += id_;
	result += dozators_;
	result += str_volume_;
	result += str_feedrate_;
	result += str_ratio_;
	result += str_reverse_;

	return result;
}

