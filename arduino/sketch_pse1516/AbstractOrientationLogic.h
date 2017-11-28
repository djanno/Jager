#ifndef _ABSTRACT_ORIENTATION_LOGIC_
#define _ABSTRACT_ORIENTATION_LOGIC_

#include "OrientationLogic.h"

#define SCAN_FOV 180 //defines the FOV of the robot during the paths scanning procedure
#define SCAN_STEP 45 //define the rotation step of the servo motor during the paths scanning procedure
#define PROBING_FOV 90 //define th FOV of the robot during the probing phase

/* This class defines an abstract OrientationLogic for the OrientationTask */
class AbstractOrientationLogic : public OrientationLogic {

	//starting position of the servo during the paths scanning procedure
	const int startingPosition = 90 - (SCAN_FOV / 2);
	//step of rotation of the servo motor during the probing phase
	int probingStep = PROBING_FOV / 2;
  
protected:
	//a proximity sensor
	ProxSens* prox;
	//a servo motor
	ServoMotor* servo;

public:
	void init();
	void attachComponents();
	virtual OrientationState stateFree();
	virtual OrientationState stateMeasure() = 0;
	virtual OrientationState stateRotateServo();
	virtual OrientationState stateFound();
		
};

#endif
