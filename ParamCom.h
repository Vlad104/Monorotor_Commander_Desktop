#pragma once
#include "Command.h"

const char identificator = '@';
const char volume_size = 4;
const char feedrate_size = 3;
const char ratio_size = 3;
const char revers_size = 3;

class ParamCom : public Command {
public:
	ParamCom();	
	ParamCom(char dozator, std::string volume, std::string feedrate, std::string ratio, std::string revers);
	//ParamCom(char dozator, std::string volume, std::string feedrate, std::string ratio_A, std::string ratio_B, std::string revers);
	~ParamCom() {};
	bool get_command(std::string& result);

private:
	char id_;
	char dozator_;
	std::string volume_;
	std::string feedrate_;
	std::string ratio_;
	std::string revers_;

	const std::string temp_volume_;
	const std::string temp_feedrate_;
	const std::string temp_ratio_;
	const std::string temp_revers_;

	bool make_command(std::string& result);
	bool prepare_string(const std::string& str, std::string& result, int expected_size);
};