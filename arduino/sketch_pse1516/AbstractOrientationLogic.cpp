#include "AbstractOrientationLogic.h"
#include "ServoImpl.h"
#include "RobotImpl.h"
#include "global.h"

#define RIGHT 90 - (PROBING_FOV / 2) //defines the RIGHT position of the servo during the probing procedure
#define LEFT 90 + (PROBING_FOV / 2) //defines the LEFT position of the servo during the probing procedure

//the central position is always 90 degrees

void AbstractOrientationLogic::attachComponents() {
	this->prox = RobotImpl::getInstance()->getProxSens();
	this->servo = RobotImpl::getInstance()->getServo();
}

void AbstractOrientationLogic::init() {
	this->servo->changePosition(90);
	chosenDirection = -1;
	detected = false;
	found = false;
}

OrientationState AbstractOrientationLogic::stateFree() {
	if (this->prox->getDistance() == 0) {
		detected = true;
		this->servo->changePosition(this->startingPosition);
		return MEASURE;
	}
	else return ROTATE_SERVO;
}

OrientationState AbstractOrientationLogic::stateRotateServo() {
	if (!detected) {
		if(this->servo->getPosition() == LEFT || this->servo->getPosition() == RIGHT) this->probingStep = -this->probingStep;
		this->servo->changePosition(this->servo->getPosition() + this->probingStep);
		return FREE;
	}
	else {
		this->servo->changePosition(this->servo->getPosition() + SCAN_STEP);
		return MEASURE;
	}
}

OrientationState AbstractOrientationLogic::stateFound() {
	if (ready) {
			found = false;
			chosenDirection = -1;
			detected = false;
			return FREE;
		}
	else return FOUND;
}
