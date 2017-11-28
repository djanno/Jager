#include "Arduino.h"
#include "ProxSensImpl.h"

#define TIMEOUT 10000

ProxSensImpl::ProxSensImpl(int echoPin, int trigPin) {
	this->echoPin = echoPin;
	this->trigPin = trigPin;
	pinMode(echoPin, INPUT);
	pinMode(trigPin, OUTPUT);
}

int ProxSensImpl::measure() const {
	digitalWrite(this->trigPin,LOW);
	delayMicroseconds(3);
	digitalWrite(this->trigPin,HIGH);
	delayMicroseconds(5);
	digitalWrite(this->trigPin,LOW);

	float tUS = pulseIn(echoPin, HIGH, TIMEOUT);
	float t = tUS / 1000.0 / 1000.0 / 2;
	return (int)(t * this->vs * 100);
}

int ProxSensImpl::getDistance() const {
	int distance = 0;
	for (int i = 0; i < ATTEMPTS && distance == 0; i++) {
		distance = this->measure();
	}
	if (distance == 0) distance = MAX_DISTANCE;
	if (distance > TOO_CLOSE) return distance;
	else return 0;
}
