#ifndef __LED__
#define __LED__

#include "Light.h"

/* This class defines a Led */
class Led : public Light {
public:
	Led(int pin);
	void switchOn();
	void switchOff();
private:
	//the pin to which the led is attached
	int pin;
};

#endif
