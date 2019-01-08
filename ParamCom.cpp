#include "ParamCom.h"

ParamCom::ParamCom() : id_(identificator) {}


ParamCom::ParamCom(char dozator, std::string volume, std::string feedrate, std::string ratio, std::string revers) :
	id_(identificator), dozator_(dozator), temp_volume_(volume),
	temp_feedrate_(feedrate), temp_ratio_(ratio), temp_revers_(revers)
{}


bool ParamCom::get_command(std::string& result) {
	return make_command(result);
}

bool ParamCom::make_command(std::string& result) {

	if (!prepare_string(temp_volume_, volume_, volume_size)) {
		volume_ = "";
		return false;
	}

	if (!prepare_string(temp_feedrate_, feedrate_, feedrate_size)) {
		feedrate_ = "";
		return false;
	}

	if (!prepare_string(temp_ratio_, ratio_, ratio_size)) {
		ratio_ = "";
		return false;
	}

	if (!prepare_string(temp_revers_, revers_, revers_size)) {
		revers_ = "";
		return false;
	}

	result += id_;
	result += dozator_;
	result += volume_;
	result += feedrate_;
	result += ratio_;
	result += revers_;

	return true;
}

bool ParamCom::prepare_string(const std::string& str, std::string& result, int expected_size) {
	if (str.size() > expected_size) {
		return false;
	}

	for (auto symbol : str) {
		if (symbol < '0' || symbol > '9') {
			return false;
		}
	}

	for (int i = 0; i < expected_size - str.size(); i++) {
		result += '0';
	}
	result += str;

	return true;
}
