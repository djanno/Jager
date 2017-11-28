#ifndef _ORIENTATION_TASK_
#define _ORIENTATION_TASK_

#include "Task.h"
#include "OrientationLogic.h"
#include "OrientationStates.h"

#define ORIENTATION_PERIOD 200

/* This class defines the OrientationTask */
class OrientationTask : public Task {

	static OrientationTask* ORIENTATION_TASK;
	//the logic
	OrientationLogic* logic;
	//the current state of the FSM related to the task
	OrientationState current;
	
	OrientationTask(OrientationLogic* logic);

public:
	static OrientationTask* getInstance();
	void init(int period);
	void tick();

	/* swaps the logic that pilots the FSM of the task with the given one */
	void changeLogic(OrientationLogic* logic);

};

#endif
