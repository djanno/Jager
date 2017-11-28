#ifndef _MOTOR_
#define _MOTOR_

#define GEAR1 80 //defines a speed in RPM of the motor, this is the speed at which the robot travels when in its autopilot mode
#define GEARX 100 //this speed constant is used only for retro and turning, do not change it
#define GEAR2 160 //defines another speed level in RPM

/* This interface defines the behaviour of a Motor */
class Motor {

public:
	/* return the current speed of the motor */
	virtual int getSpeed() const = 0;
	/* sets the speed of the motor to the given one */
	virtual void setSpeed(int speed) = 0;

};

#endif
