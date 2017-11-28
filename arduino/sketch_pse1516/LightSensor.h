#ifndef __LIGHTSENSOR__
#define __LIGHTSENSOR__

/* This interface defines the behaviour of a LightSensor */
class LightSensor {

public:
  /* returns the current light level */
  virtual int getCurrentLight() const = 0;
  /* returns whether or not the light level of the environment is below a specific threshold */
  virtual bool isLightBelowThreshold() const = 0;
  
};
#endif
