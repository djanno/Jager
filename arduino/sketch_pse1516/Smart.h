#ifndef _SMART_
#define _SMART_

#include "AbstractOrientationLogic.h"

/* This class defines a Smart OrientationLogic for the OrientationTask */
class Smart : public AbstractOrientationLogic {

	//holds the maximum distance recorded
	int distance;
	//holds the direction in which the maximum distance has been recorded
	int direction;

public:
	Smart();
	virtual OrientationState stateMeasure();

};

#endif
