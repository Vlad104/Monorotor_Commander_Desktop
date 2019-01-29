#ifndef ACTION_PROTOCOL_H
#define ACTION_PROTOCOL_H

#include "Protocol.h"


class ActionProtocol : public Protocol {
public:
	ActionProtocol();
	ActionProtocol(char mode, char action);
	~ActionProtocol() = default;
	std::string get_command();

private:
	const char id_ = '=';
	char mode_;
	char action_;

	std::string make_command();
};


#endif // ACTION_PROTOCOL_H