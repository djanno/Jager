#ifndef _ORIENTATION_LOGIC_
#define _ORIENTATION_LOGIC_

#include "OrientationStates.h"
#include "ServoMotor.h"
#include "ProxSens.h"


/* This interface defines the behaviour of an OrientationLogic for the OrientationTask */
class OrientationLogic {

public:
	/* initializes the FSM piloted by this logic */
	virtual void init() = 0;
	/* retrieves and attaches the proximity sensor and the servo motor to the logic */
	virtual void attachComponents() = 0;
	/* handles the behaviour of the FSM on its FREE state */
	virtual OrientationState stateFree() = 0;
	/* handles the behaviour of the FSM on its MEASURE state */
	virtual OrientationState stateMeasure() = 0;
	/* handles the behaviour of the FSM on its ROTATE_SERVO state */
	virtual OrientationState stateRotateServo() = 0;
	/* handles the behaviour of the FSM on its FOUND state */
	virtual OrientationState stateFound() = 0;
};


#endif
