#include "Factory.h"
#include "ActCom.h"

class ActionFactory {
	ActionFactory() {};
	~ActionFactory() {};
	Command create_command() {
		return new ActCom();
	}
}