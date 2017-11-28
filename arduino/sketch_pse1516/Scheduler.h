#ifndef _SCHEDULER_
#define _SCHEDULER_

#include "Task.h"
#include "Timer.h"

#define MAX_TASKS 5

/* This class defines the scheduler */
class Scheduler {

	//the scheduler period
	int basePeriod;
	//the current number of task that are being scheduled
	int nTasks;
	//the list of tasks that are being scheduled
	Task* list[MAX_TASKS];
	//the timer used to calibrate the scheduler
	Timer timer;

public:
	/* initializes the scheduler with the given period */
	void init(int basePeriod);
	/* adds a task to the scheduling queue */
	virtual bool addTask(Task* task);
	/* starts the scheduling procedure */
	virtual void schedule();

};

#endif