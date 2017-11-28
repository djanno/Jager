#ifndef _LIGHT_CONTROL_LOGIC_IMPL_
#define _LIGHT_CONTROL_LOGIC_IMPL_

#include "LightControlLogic.h"
#include "Robot.h"

/* This class defines a LightControlLogic for the LightControlTask */
class LightControlLogicImpl : public LightControlLogic {

protected:
	//lights
	Light* lights[LIGHTS];
	//light sensor
	LightSensor* sensor;

public:
	LightControlLogicImpl();
	void init();
	virtual LightControlState stateOff();
	virtual LightControlState stateOn();

};

#endif
