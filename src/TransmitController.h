#ifndef TRANSMIT_CONTROLLER_H
#define TRANSMIT_CONTROLLER_H

#include <queue>
#include <string>
#include "DataModel.h"
#include "Protocol.h"

class TransmitController {
public:
	TransmitController() = default;
	~TransmitController() = default;

	bool is_empty();
	std::string get_command();

	void get_stop();
	void get_start(const DataModel& order);
	void get_continues(const DataModel& order);
    void clear_story();

private:
	std::queue<std::string>	transmit_data_;
	DataModel				prev_model_;

	void add_transmit_data(const DataModel& model);
    void clear_transmit_order();
};

#endif // TRANSMIT_CONTROLLER_H
