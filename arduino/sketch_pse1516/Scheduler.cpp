#include "Scheduler.h"

void Scheduler::init(int basePeriod) {
	this->basePeriod = basePeriod;
	this->timer.setupPeriod(basePeriod);
	this->nTasks = 0;
}

bool Scheduler::addTask(Task* task) {
	if (this->nTasks < MAX_TASKS) {
		this->list[this->nTasks++] = task;
		return true;
	}
	else {
		return false;
	}
}

void Scheduler::schedule() {
	timer.waitForNextTick();
	for (int i = 0; i < this->nTasks; i++) {
		if (!this->list[i]->asleep() && this->list[i]->updateAndCheckTime(this->basePeriod)) {
			this->list[i]->tick();
		}
	}
}
