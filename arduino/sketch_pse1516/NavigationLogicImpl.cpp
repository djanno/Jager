#include "NavigationLogicImpl.h"
#include "MotorImpl.h"
#include "RobotImpl.h"
#include "global.h"

#define TURNING_CONST 45 //constant used for the turning procedure, it's linked to the speed at which the robot turns and the tick period of the task, do not change

NavigationLogicImpl::NavigationLogicImpl() {
	this->left = RobotImpl::getInstance()->getLeftMotor();
	this->right = RobotImpl::getInstance()->getRightMotor();
	this->ticks = 0;
}

void NavigationLogicImpl::init() {
	this->left->setSpeed(GEAR1);
	this->right->setSpeed(GEAR1);
	ready = false;
}

NavigationState NavigationLogicImpl::stateMoving() {
	if (detected) {
		this->left->setSpeed(0);
		this->right->setSpeed(0);
		return STOPPED;
	}
	else return MOVING;
}

NavigationState NavigationLogicImpl::stateStopped() {
	if (found) {
		this->left->setSpeed(-GEARX);
		this->right->setSpeed(-GEARX);
		return RETRO;
	}
	else return STOPPED;
}

NavigationState NavigationLogicImpl::stateRetro() {
	int direction = 90 - chosenDirection;
	if (direction > 0) this->ticks = direction / TURNING_CONST;
	else this->ticks = -direction / TURNING_CONST;
	this->left->setSpeed(0);
	this->right->setSpeed(0);
	if (direction > 0) this->left->setSpeed(GEARX);
	if (direction < 0) this->right->setSpeed(GEARX);
	return STEERING;
}

NavigationState NavigationLogicImpl::stateSteering() {
	if (this->ticks > 0) {
    this->ticks--;
    return STEERING;
	}
	else {
		this->left->setSpeed(0);
    this->right->setSpeed(0);
    ready = true;
    return READY;
	}
}

NavigationState NavigationLogicImpl::stateReady() {
	if (!detected) {
		ready = false;
		this->left->setSpeed(GEAR1);
		this->right->setSpeed(GEAR1);
		return MOVING;
	}
	else return READY;
}
