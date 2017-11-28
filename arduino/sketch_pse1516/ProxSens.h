#ifndef __PROXSENS__
#define __PROXSENS__

#define ATTEMPTS 5 //defines the number of attempts at recording a valid measurement
#define TOO_CLOSE 30 //defines the minimum distance threshold
#define MAX_DISTANCE 200 //defines a max distance constant

/* This interface defines the behaviour of a ProxSens */
class ProxSens {

public:
	/* returns the distance to a given object, 0 if the measurement failed*/
	virtual int measure() const = 0;
	/* attempts for ATTEMPTS times to calculate the distance of an object. Failed measurements are discarded, if all measurements fail, MAX_DISTANCE is returned.
	   As soon as a valid measurement has been recorded, it is returned if it's greater than TOO_CLOSE, otherwise 0 is returned */
	virtual int getDistance() const = 0;
  
};

#endif
