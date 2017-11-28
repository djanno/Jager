#ifndef _LIGHT_SENSOR_IMPL_
#define _LIGHT_SENSOR_IMPL_

#include "LightSensor.h"

#define THRESHOLD 40;

/* This class defines a LightSensor */
class LightSensorImpl : public LightSensor {

public:
	LightSensorImpl(int pin);
	int getCurrentLight() const;
	bool isLightBelowThreshold() const;

private:
	//pin number to which the light sensor is attached
	int pin;
};
#endif
