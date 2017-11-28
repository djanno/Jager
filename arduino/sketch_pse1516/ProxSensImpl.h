#ifndef _PROX_SENS_IMPL_
#define _PROX_SENS_IMPL__

#include "ProxSens.h"

/* This class defines a ProxSens */
class ProxSensImpl : public ProxSens {

public:
	ProxSensImpl(int echoPin, int trigPin);
	int measure() const;
	int getDistance() const;

private:
	//the echo pin number
	int echoPin;
	//the trigger pin number
	int trigPin;
	//constant used for conversion from echo period to distance
	const float vs = 331.5 + 0.6*20;
};

#endif
