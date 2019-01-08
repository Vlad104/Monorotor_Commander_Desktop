#include "Factory.h"
#include "ParamCom.h"

class ParamFactory {
	ParamFactory() {};
	~ParamFactory() {};
	Command create_command() {
		return new ParamCom();
	}
}