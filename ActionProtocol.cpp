#include "ActionProtocol.h"

ActionProtocol::ActionProtocol() :
	id_('='), mode_('0'), action_('0')
{}

ActionProtocol::ActionProtocol(char mode, char action) :
	id_('='), mode_(mode), action_(action)
{}

bool ActionProtocol::get_command(std::string& result) {
	return make_command(result);
}

bool ActionProtocol::make_command(std::string& result) {

	result += id_;
	result += mode_;
	result += action_;

	return true;
}