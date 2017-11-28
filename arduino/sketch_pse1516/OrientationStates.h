#ifndef _ORIENTATION_STATES_
#define _ORIENTATION_STATES_

/* This enum defines the states of the FSM linked to the OrientationTask */
enum OrientationState { FREE, MEASURE, ROTATE_SERVO, FOUND };

#endif
