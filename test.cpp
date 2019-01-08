#include <iostream>
#include "ParamCom.h"
#include "ActCom.h"

int main() {
	std::cout << "START" << std::endl;

	Command* command;
	int command_type = 0;

	if (command_type == 0) {
		command = new ParamCom('2', "0150", "160", "750", "010");
	} else if (command_type == 1) {
		command = new ActCom('0', '1');
	} else {
		std::cout << "ERROR 1" << std::endl;
		return 0;
	}

	std::string result;
	if (command->get_command(result)) {
		std::cout << result << std::endl;
		std::cout << "OK" << std::endl;		
	} else {
		std::cout << "ERROR 2" << std::endl;		
	}
	delete command;
	return 0;
}