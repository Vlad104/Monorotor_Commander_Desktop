#pragma once
#include <string>

struct Command {
	Command() {};
	virtual ~Command() {};
	virtual bool get_command(std::string& result) = 0;
};