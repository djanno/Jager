#ifndef _ROBOT_IMPL_
#define _ROBOT_IMPL_

#include "Robot.h"

/* This class defines the robot */
class RobotImpl : public Robot {
	//the robot
	static Robot* JAGER;
	//the lights attached to the robot
	Light* lights[LIGHTS];
	//the light sensor attached to the robot
	LightSensor* lightSensor;
	//the proximity sensor attached to the robot
	ProxSens* prox;
	//the servo motor attached to the robot
	ServoMotor* servo;
	//the motor shield attached to the robot
	Adafruit_MotorShield* shield;
	//the left motor attached to the robot
	Motor* left;
	//the right motor attached to the robot
	Motor* right;
	//the message box attached to the robot
	MessageBox* messageBox;

	RobotImpl();
  
public:
	static Robot* getInstance();
	Light* getLight(int index) const;
	LightSensor* getLightSensor() const;
	ProxSens* getProxSens() const;
	ServoMotor* getServo() const;
	Adafruit_MotorShield* getMotorShield() const;
	Motor* getLeftMotor() const;
	Motor* getRightMotor() const;
	MessageBox* getMessageBox() const;
	void reset();
};

#endif
