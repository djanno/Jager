#ifndef _TASK_
#define _TASK_

/* This class defines an abstract task */
class Task {

	//period of execution of the task
	int tickPeriod;
	//time elapsed since the last tick
	int timeElapsed;
	//expresses whether the task is in a sleeping state or not
	bool sleeping;

public:
	/* initializes the task with the given period as the execution (tick) period */
	virtual void init(int period);
	/* virtual method that defines the behaviour of the task each time its period ticks */
	virtual void tick() = 0;
	/* updates the time elapsed and checks if enough time has passed for the task to execute */
	bool updateAndCheckTime(int period);
	/* returns whether the task is asleep or not */
	bool asleep() const;
	/* puts the task to sleep */
	void sleep();
	/* re initializes the task */
	void reset();

};

#endif