#include "Smart.h"
#include "global.h"

Smart::Smart() {
	AbstractOrientationLogic::attachComponents();
	this->distance = 0;
	this->direction = -1;
}

OrientationState Smart::stateMeasure() {
	int record = this->prox->getDistance();
	if (record > this->distance) {
	  this->distance = record;
    this->direction = this->servo->getPosition();
	}
	if (this->servo->getPosition() < SCAN_FOV) return ROTATE_SERVO;
	else {
		this->distance > 0 ? chosenDirection = this->direction : chosenDirection = 270;
		this->distance = 0;
    this->direction = -1;
    this->servo->changePosition(90);
		found = true;
		return FOUND;
	}
}
