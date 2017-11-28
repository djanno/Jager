#ifndef _MOTOR_IMPL_
#define _MOTOR_IMPL_

#include "Motor.h"
#include <Adafruit_MotorShield.h>

/* This class is a wrapper class for the Adafruit DCMotor class and defines a Motor */
class MotorImpl : public Motor {

	//the motor offered by the Adafruit library
	Adafruit_DCMotor* motor;
	//the speed of the motor, negative means it's going backward, positive means it's going forward
	int speed;

public:
	MotorImpl(Adafruit_DCMotor* motor);
	int getSpeed() const;
	void setSpeed(int speed);
};

#endif
