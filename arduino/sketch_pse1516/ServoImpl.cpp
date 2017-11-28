#include "ServoImpl.h"
#include "Arduino.h"

ServoImpl::ServoImpl(int pin) {
	this->servo.attach(pin);
	this->changePosition(90);
}

void ServoImpl::changePosition(int newPosition) {
  if(newPosition < 0) newPosition = 0;
  if(newPosition > 180) newPosition = 180;
  int pulseWidth = map(newPosition, 0, 180, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
	this->servo.write(pulseWidth);
	this->position = newPosition;
}

int ServoImpl::getPosition() const {
	return this->position;
}
