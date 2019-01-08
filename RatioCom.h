#pragma once
#include <vector>
#include <iomanip>

#include "Command.cpp"

class RatioCom : public Command {
public:
	RatioCom();
	~RatioCom();
	std::vector<char> get_command();

private:
	char id_;
	char dozator_;
	char ratio_;
	double d_ratio_;

	std::vector<char> make_command();
};

void RatioCom::make_ratio() {
	std::ssteam s;
	s << std::setprecision(6) << d_ratio_;
	std::string str = s.str();
	char result[12];
	int i = 0;
	if (str.size() < 12 - i) {
		result[i] = '0';
		i++
	}
	int str_pos = i;
	while (i < 12) {
		result[i] = str[i - str_pos];
		i++;
	}
	// проверка записи всех целых цифр??
	return result;
}