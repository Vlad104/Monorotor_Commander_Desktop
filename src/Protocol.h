#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <string>
#include <sstream>

class Protocol {
public:
	Protocol() = default;
	~Protocol() = default;

	static std::string make_dozators(char dozators);
	static std::string make_volume(double volume);
	static std::string make_feedrate(double volume);
	static std::string make_accel(double volume);
	static std::string make_gear_A(double volume);
	static std::string make_gear_B(double volume);
	static std::string make_ratio(double volume);

	static std::string make_start();
	static std::string make_stop();
	static std::string make_continues();

private:
	static std::string convert_to_string(double value);
};

#endif // PROTOCOL_H