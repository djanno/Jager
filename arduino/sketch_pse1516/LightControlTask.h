#ifndef _LIGHT_CONTROL_TASK_
#define _LIGHT_CONTROL_TASK_

#include "Task.h"
#include "LightControlLogic.h"
#include "LightControlStates.h"

#define LIGHT_CONTROL_PERIOD 500

/* Class for the light control task */
class LightControlTask : public Task {

	static LightControlTask* LIGHT_TASK;
	//the logic
	LightControlLogic* logic;
	//the current state of the FSM linked to the task
	LightControlState current;

	LightControlTask(LightControlLogic* logic);
	
public:
	static LightControlTask* getInstance();
	void init(int period);
	void tick();

	/* swaps the logic that pilots the FSM linked to the task with the given one */
	void changeLogic(LightControlLogic* logic);

};

#endif
