#include "NavigationTask.h"
#include "NavigationLogicImpl.h"

NavigationTask* NavigationTask::NAVIGATION_TASK = nullptr;

NavigationTask::NavigationTask(NavigationLogic* logic) {
	this->logic = logic;
}

NavigationTask* NavigationTask::getInstance() {
	if(NAVIGATION_TASK == nullptr) NAVIGATION_TASK = new NavigationTask(new NavigationLogicImpl());
	return NAVIGATION_TASK;
}

void NavigationTask::init(int period) {
	Task::init(period);
	this->logic->init();
	this->current = MOVING;
}

void NavigationTask::tick() {
  switch (this->current) {
    case MOVING:
		this->current = this->logic->stateMoving();
		break;
    case STOPPED:
		this->current = this->logic->stateStopped();
		break;
    case RETRO:
		this->current = this->logic->stateRetro();
		break;
    case STEERING:
		this->current = this->logic->stateSteering();
		break;
    case READY:
		this->current = this->logic->stateReady();
		break;
  }
}

void NavigationTask::changeLogic(NavigationLogic* logic) {
	delete(this->logic);
	this->logic = logic;
	this->reset();
}
