#ifndef _LIGHT_CONTROL_LOGIC_
#define _LIGHT_CONTROL_LOGIC_

#include "LightControlStates.h"

/* This interface defines the behaviour of a generic LightControlLogic for the LightControlTask */
class LightControlLogic {

public:
	/* initializes the FSM piloted by this logic */
	virtual void init() = 0;
	/* handles the behaviour of the FSM piloted by this logic in its OFF state */
	virtual LightControlState stateOff() = 0;
	/* handles the behaviour of the FSM piloted by this logic in its ON state */
	virtual LightControlState stateOn() = 0;

};

#endif
