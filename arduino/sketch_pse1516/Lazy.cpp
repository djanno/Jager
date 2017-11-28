#include "Lazy.h"
#include "global.h"

Lazy::Lazy() {
	AbstractOrientationLogic::attachComponents();
}

OrientationState Lazy::stateMeasure() {
	if (this->prox->getDistance() > 0) {
		chosenDirection = this->servo->getPosition();
    this->servo->changePosition(90);
		found = true;
		return FOUND;
	}
	if (this->servo->getPosition() < SCAN_FOV) return ROTATE_SERVO;
	else {
		chosenDirection = 270;
    this->servo->changePosition(90);
		found = true;
		return FOUND;
	}
}
