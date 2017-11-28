#ifndef __SERVO__
#define __SERVO__

#include "ServoMotor.h"
#include "ServoTimer2.h"

/* This class is a wrapper class for the servo motor offered by the ServoTimer2 library. It defines a ServoMotor */
class ServoImpl : public ServoMotor {

	//the servo
	ServoTimer2 servo;
	//its current position
	float position;

public:
	ServoImpl(int pin);
	void changePosition(int newPosition);
	int getPosition() const;
};
#endif
