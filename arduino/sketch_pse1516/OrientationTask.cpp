#include "OrientationTask.h"
#include "Smart.h"

OrientationTask* OrientationTask::ORIENTATION_TASK = nullptr;

OrientationTask::OrientationTask(OrientationLogic* logic) {
	this->logic = logic;
}

OrientationTask* OrientationTask::getInstance() {
	if(ORIENTATION_TASK == nullptr) ORIENTATION_TASK = new OrientationTask(new Smart());
	return ORIENTATION_TASK;
}

void OrientationTask::init(int period) {
	Task::init(period);
	this->logic->init();
	this->current = FREE;
}

void OrientationTask::tick() {
	switch (this->current) {
	case FREE:
		this->current = this->logic->stateFree();
		break;
	case MEASURE:
		this->current = this->logic->stateMeasure();
		break;
	case ROTATE_SERVO:
		this->current = this->logic->stateRotateServo();
		break;
	case FOUND:
		this->current = this->logic->stateFound();
		break;
	}
}

void OrientationTask::changeLogic(OrientationLogic* logic) {
	delete(this->logic);
	this->logic = logic;
	this->reset();
}
