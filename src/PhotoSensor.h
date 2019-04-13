#ifndef PhotoSensor_h
#define PhotoSensor_h
#include "Arduino.h"

class PhotoSensor
{
  public:
    PhotoSensor(uint8_t pin);
    void loop(); //should be called every arduino loop
    float getCurrentLuxValue();
  private:
    uint8_t _pin; //green light pin location
    float _lastValue; //Voltage last read value
};

#endif
