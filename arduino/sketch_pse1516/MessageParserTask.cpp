#include "MessageParserTask.h"
#include "MessageParserLogicImpl.h"

MessageParserTask* MessageParserTask::MESSAGE_TASK = nullptr;

MessageParserTask::MessageParserTask(MessageParserLogic* logic) {
	this->logic = logic;
}

MessageParserTask* MessageParserTask::getInstance() {
	if(MESSAGE_TASK == nullptr) MESSAGE_TASK = new MessageParserTask(new MessageParserLogicImpl());
	return MESSAGE_TASK;
}

void MessageParserTask::init(int period) {
	Task::init(period);
	this->current = LISTENING;
}

void MessageParserTask::tick() {
	switch (this->current) {
	case LISTENING:
		this->logic->stateListening();
	}
}

void MessageParserTask::changeLogic(MessageParserLogic* logic) {
	delete(this->logic);
	this->logic = logic;
	this->reset();
}
