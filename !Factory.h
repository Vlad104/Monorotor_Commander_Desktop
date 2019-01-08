#include "Command.h"

struct Factory {
	Factory() {};
	virtual ~Factory() {};
	virtual Command create_command() = 0;
}