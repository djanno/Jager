#ifndef _NAVIGATION_LOGIC_IMPL_
#define _NAVIGATION_LOGIC_IMPL_

#include "NavigationLogic.h"
#include "Motor.h"


/* This class defines a NavigationLogic for the NavigationTask */
class NavigationLogicImpl : public NavigationLogic {

	//ticks that the robot has to spend in its STEERING state in order for it to steer towards the chosenDirection
	int ticks;

protected:
	//left motor
	Motor* left;
	//right motor
	Motor* right;
	

public:
	NavigationLogicImpl();
	void init();
	virtual NavigationState stateMoving();
	virtual NavigationState stateStopped();
	virtual NavigationState stateRetro();
	virtual NavigationState stateSteering();
	virtual NavigationState stateReady();
};

#endif
