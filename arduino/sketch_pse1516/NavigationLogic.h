#ifndef _NAVIGATION_LOGIC_
#define _NAVIGATION_LOGIC_

#include "NavigationStates.h"

/* This interface defines the behaviour of a NavigationLogic for the NavigationTask */
class NavigationLogic {

public:
	/* initializes the FSM piloted by this logic */
	virtual void init() = 0;
	/* handles the behaviour of the FSM piloted by this logic in its MOVING state */
	virtual NavigationState stateMoving() = 0;
	/* handles the behaviour of the FSM piloted by this logic in its STOPPED state */
	virtual NavigationState stateStopped() = 0;
	/* handles the behaviour of the FSM piloted by this logic in its RETRO state */
	virtual NavigationState stateRetro() = 0;
	/* handles the behaviour of the FSM piloted by this logic in its STEERING state */
	virtual NavigationState stateSteering() = 0;
	/* handles the behaviour of the FSM piloted by this logic in its READY state */
	virtual NavigationState stateReady() = 0;
};

#endif
