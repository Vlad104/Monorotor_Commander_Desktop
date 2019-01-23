#include "ParametersProtocol.h"

ParametersProtocol::ParametersProtocol() : 
	dozators_('2'), volume_(0), feedrate_(0), ratio_(0.5), revers_(0)
{}


ParametersProtocol::ParametersProtocol(char dozators, uint16_t volume, uint16_t feedrate, double ratio, uint16_t revers) :
	dozators_(dozators), volume_(volume), feedrate_(feedrate), ratio_(ratio), revers_(revers);  // с домножением на 10 итд разобраться
{
	volume_ /= 100;		// ul -> ml and then x10
	feedrate_ /= 1000;	// ul/min -> ml/min;
	revers_ /= 10;		// (procents) x10
}


bool ParametersProtocol::get_command(std::string& result) {
	return make_command(result);
}

bool ParametersProtocol::make_command(std::string& result) {

	str_volume_ = convert_to_string(volume_, volume_size);
	str_feedrate_ = convert_to_string(feedrate_, feedrate_size);
	str_ratio_ = convert_to_string(ratio_, 0, ratio_size);
	str_revers_ = convert_to_string(revers_, revers_size);

	result += id_;
	result += dozator_;
	result += volume_;
	result += feedrate_;
	result += ratio_;
	result += revers_;

	return true;
}

