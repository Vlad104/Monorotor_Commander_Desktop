#pragma once
#include "Command.h"

class ActCom : public Command {
public:
	ActCom();
	ActCom(char mode, char action);
	~ActCom() {};
	bool get_command(std::string& result);

private:
	char id_;
	char mode_;
	char action_;

	bool make_command(std::string& result);
};