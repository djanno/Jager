#include "Task.h"

void Task::init(int period) {
	this->tickPeriod = period;
	this->timeElapsed = 0;
	this->sleeping = false; //by default, a task is not sleeping
}

bool Task::updateAndCheckTime(int period) {
	this->timeElapsed += period;
	if (this->timeElapsed >= this->tickPeriod) {
		this->timeElapsed = 0;
		return true;
	}
	else {
		return false;
	}
}

bool Task::asleep() const {
	return this->sleeping;
}

void Task::sleep() {
	this->sleeping = true;
}

void Task::reset() {
	this->init(this->tickPeriod);
}
