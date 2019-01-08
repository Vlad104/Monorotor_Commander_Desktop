#include "ActCom.h"

ActCom::ActCom() :
	id_('='), mode_('0'), action_('0')
{}

ActCom::ActCom(char mode, char action) :
	id_('='), mode_(mode), action_(action)
{}

bool ActCom::get_command(std::string& result) {
	return make_command(result);
}

bool ActCom::make_command(std::string& result) {

	result += id_;
	result += mode_;
	result += action_;

	return true;
}