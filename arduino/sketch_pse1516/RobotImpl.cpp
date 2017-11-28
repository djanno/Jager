#include "RobotImpl.h"
#include "Led.h"
#include "LightSensorImpl.h"
#include "ProxSensImpl.h"
#include "ServoImpl.h"
#include "MotorImpl.h"
#include "MessageBoxImpl.h"
#include "global.h"

#define LEDPIN1 13
#define LEDPIN2 12
#define LIGHTSENSORPIN A0
#define ECHOPIN 9
#define TRIGPIN 10
#define SERVOPIN 11
#define LEFTMOTOR 2
#define RIGHTMOTOR 1

Robot* RobotImpl::JAGER = nullptr;

RobotImpl::RobotImpl() {
	this->lights[0] = new Led(LEDPIN1);
	this->lights[1] = new Led(LEDPIN2);
	this->lightSensor = new LightSensorImpl(LIGHTSENSORPIN);
	this->prox = new ProxSensImpl(ECHOPIN, TRIGPIN);
	this->servo = new ServoImpl(SERVOPIN);
	this->shield = new Adafruit_MotorShield();
	this->left = new MotorImpl(this->shield->getMotor(LEFTMOTOR));
	this->right = new MotorImpl(this->shield->getMotor(RIGHTMOTOR));
	this->messageBox = new MessageBoxImpl();
	this->shield->begin();
}

Robot* RobotImpl::getInstance() {
  if(JAGER == nullptr) JAGER = new RobotImpl();
  return JAGER;  
}

Light* RobotImpl::getLight(int index) const {
	return this->lights[index];
}

LightSensor* RobotImpl::getLightSensor() const {
	return this->lightSensor;
}

ProxSens* RobotImpl::getProxSens() const {
	return this->prox;
}

ServoMotor* RobotImpl::getServo() const {
	return this->servo;
}

Adafruit_MotorShield* RobotImpl::getMotorShield() const {
	return this->shield;
}

Motor* RobotImpl::getLeftMotor() const {
	return this->left;
}

Motor* RobotImpl::getRightMotor() const {
	return this->right;
}

MessageBox* RobotImpl::getMessageBox() const {
	return this->messageBox;
}

void RobotImpl::reset() {
	this->servo->changePosition(90); //servo to neutral;
	this->left->setSpeed(0);
	this->right->setSpeed(0); //stops the robot
	for (int i = 0; i < LIGHTS; i++) { //lights off
		this->lights[i]->switchOff(); 
	}
}
