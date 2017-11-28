#ifndef _ROBOT_
#define _ROBOT_

#include <Adafruit_MotorShield.h>
#include "Light.h"
#include "LightSensor.h"
#include "ProxSens.h"
#include "ServoMotor.h"
#include "Motor.h"
#include "MessageBox.h"

#define LIGHTS 2

/* This interface defines the behaviour of the robot */
class Robot {

public:
	/* returns the light attached to the robot at the given index */
	virtual Light* getLight(int index) const = 0;
	/* returns the light sensor attached to the robot */
	virtual LightSensor* getLightSensor() const = 0;
	/* returns the proximity sensor attached to the robot */
	virtual ProxSens* getProxSens() const = 0;
	/* returns the servo motor attached to the robot */
	virtual ServoMotor* getServo() const = 0;
	/* returns the motorshield attached to the robot */
	virtual Adafruit_MotorShield* getMotorShield() const = 0;
	/* returns the left motor attached to the robot */
	virtual Motor* getLeftMotor() const = 0;
	/* returns the right motor attached to the robot */
	virtual Motor* getRightMotor() const = 0;
	/* returns the message box attached to the robot */
	virtual MessageBox* getMessageBox() const = 0;
	/* resets the robot */
	virtual void reset();
};

#endif