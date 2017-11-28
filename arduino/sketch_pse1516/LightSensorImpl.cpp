#include "LightSensorImpl.h"
#include "Arduino.h"

LightSensorImpl::LightSensorImpl(int pin) {
	this->pin = pin;
}

int LightSensorImpl::getCurrentLight() const {
	return map(analogRead(pin), 0, 1000, 0, 255);
}

bool LightSensorImpl::isLightBelowThreshold() const {
	return this->getCurrentLight() < THRESHOLD;
}
