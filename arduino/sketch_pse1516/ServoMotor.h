#ifndef _SERVO_
#define _SERVO_

/* This interface defines the behaviour of a ServoMotor */
class ServoMotor {

public:
	/* changes the servo position to the given one */
	virtual void changePosition(int position) = 0;
	/* returns the current position of the servo */
	virtual int getPosition() const = 0;
};

#endif