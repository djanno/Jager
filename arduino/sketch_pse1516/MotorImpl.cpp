#include "MotorImpl.h"

MotorImpl::MotorImpl(Adafruit_DCMotor* motor) {
	this->motor = motor;
}

int MotorImpl::getSpeed() const {
	return this->speed;
}

void MotorImpl::setSpeed(int speed) {
	if (speed < 0) {
		this->motor->run(BACKWARD);
		this->motor->setSpeed(-speed);
	}
	else {
		this->motor->run(FORWARD);
		this->motor->setSpeed(speed);
	}
}