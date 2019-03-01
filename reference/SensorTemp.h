#ifndef SensorTemp_h
#define SensorTemp_h
#include "Arduino.h"

class SensorTemp
{
  public:
    SensorTemp(uint8_t pin);
    void loop(); //should be called every arduino loop
    float getCurrentCValue();
    float getCurrentFValue();
  private:
    uint8_t _pin; //green light pin location
    float _lastValue; //Voltage last read value
};

#endif
