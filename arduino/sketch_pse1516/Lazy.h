#ifndef _LAZY_
#define _LAZY_

#include "AbstractOrientationLogic.h"

/* This class defines a Lazy OrientationLogic for the OrientationTask */
class Lazy : public AbstractOrientationLogic {

public:
	Lazy();
	virtual OrientationState stateMeasure();

};

#endif