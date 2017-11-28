#include "LightControlTask.h"
#include "LightControlLogicImpl.h"

LightControlTask* LightControlTask::LIGHT_TASK = nullptr;

LightControlTask::LightControlTask(LightControlLogic* logic) {
	this->logic = logic;
}

LightControlTask* LightControlTask::getInstance() {
	if(LIGHT_TASK == nullptr) LIGHT_TASK = new LightControlTask(new LightControlLogicImpl());
	return LIGHT_TASK;
}

void LightControlTask::init(int period) {
	Task::init(period);
	this->logic->init();
	this->current = OFF;
}

void LightControlTask::tick() {
	switch (this->current) {
	case OFF:
		this->current = this->logic->stateOff();
		break;
	case ON:
		this->current = this->logic->stateOn();
		break;
	}
}

void LightControlTask::changeLogic(LightControlLogic* logic) {
	delete(this->logic);
	this->logic = logic;
	this->reset();
}
