#ifndef LightController_h
#define LightController_h
#include "Arduino.h"

class LightController
{
  public:
    LightController(uint8_t pin);
    void loop(); //should be called every arduino loop
    int getState();
    void setState(int state);
  private:
    unsigned long _blinkStamp; //last red blink time stamp
    int _blinkState; //last red blink state
    uint8_t _pin; // light pin location
    int _state;
    //functions
    void _reloadStates();
    void _blink();
};

#endif
