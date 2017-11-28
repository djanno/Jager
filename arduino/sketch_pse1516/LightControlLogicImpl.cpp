#include "LightControlLogicImpl.h"
#include "LightSensorImpl.h"
#include "Led.h"
#include "RobotImpl.h"
#include "global.h"

LightControlLogicImpl::LightControlLogicImpl() {
	for (int i = 0; i < LIGHTS; i++) this->lights[i] = RobotImpl::getInstance()->getLight(i);
	this->sensor = RobotImpl::getInstance()->getLightSensor();
}

void LightControlLogicImpl::init() {
	for(int i = 0; i < LIGHTS; i++) this->lights[i]->switchOff();
}

LightControlState LightControlLogicImpl::stateOff() {
	if ((detected && !found) || this->sensor->isLightBelowThreshold()) {
		for (int i = 0; i < LIGHTS; i++) this->lights[i]->switchOn();
		return ON;
	}
	else return OFF;
}

LightControlState LightControlLogicImpl::stateOn() {
	if ((detected && !found) || !this->sensor->isLightBelowThreshold()) {
		for (int i = 0; i < LIGHTS; i++) this->lights[i]->switchOff();
		return OFF;
	}
	else return ON;
}
