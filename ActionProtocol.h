#pragma once
#include "Protocol.h"

class ActionProtocol : public Protocol {
public:
	ActionProtocol();
	ActionProtocol(char mode, char action);
	~ActionProtocol() {};
	bool get_command(std::string& result);

private:
	char id_;
	char mode_;
	char action_;

	bool make_command(std::string& result);
};