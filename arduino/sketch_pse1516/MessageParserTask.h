#ifndef _MESSAGE_PARSER_TASK_
#define _MESSAGE_PARSER_TASK_

#include "Task.h"
#include "MessageParserLogic.h"
#include "MessageParserStates.h"

#define MESSAGE_PARSER_PERIOD 125

/* This class defines a MessageParserTask */
class MessageParserTask : public Task {
	
	static MessageParserTask* MESSAGE_TASK;
	//the logic
	MessageParserLogic* logic;
	//the current state of the FSM linked to the task
	MessageParserState current;
	
	MessageParserTask(MessageParserLogic* logic);
	
public:
	static MessageParserTask* getInstance();
	void init(int period);
	void tick();
	
	/* swaps the logic that pilots the FSM linked to the task with the given one */
	void changeLogic(MessageParserLogic* logic);

};

#endif
