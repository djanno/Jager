#ifndef __LIGHT__
#define __LIGHT__

/* This interface defines the behaviour of a generic light */
class Light {
public:
	/* switches the light on */
	virtual void switchOn() = 0;
	/* switches the light off */
	virtual void switchOff() = 0;
};

#endif
