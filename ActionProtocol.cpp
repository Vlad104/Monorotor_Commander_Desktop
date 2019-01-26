#include "ActionProtocol.h"

ActionProtocol::ActionProtocol() :
	mode_('0'), action_('0')
{}

ActionProtocol::ActionProtocol(char mode, char action) :
	mode_(mode), action_(action)
{}

std::string ActionProtocol::get_command() {
	return make_command();
}

std::string ActionProtocol::make_command() {
	std::string result;

	result += id_;
	result += mode_;
	result += action_;

	return result;
}