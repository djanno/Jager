#ifndef _NAVIGATION_TASK_
#define _NAVIGATION_TASK_

#include "Task.h"
#include "NavigationLogic.h"
#include "NavigationStates.h"

#define NAVIGATION_PERIOD 375

/* This class defines the NavigationTask */
class NavigationTask : public Task {

	static NavigationTask* NAVIGATION_TASK;
	//the logic
	NavigationLogic* logic;
	//the current state of the FSM linked to the task
	NavigationState current;
	
	NavigationTask(NavigationLogic* logic);

public:
	static NavigationTask* getInstance();
	void init(int period);
	void tick();

	/* swaps the logic that pilots the FSM linked to the task with the given one */
	void changeLogic(NavigationLogic* logic);

};

#endif
