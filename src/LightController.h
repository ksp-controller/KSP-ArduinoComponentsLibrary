#ifndef LightController_h
#define LightController_h
#include "Arduino.h"

class LightController
{
  public:
    LightController(uint8_t pin);
    bool getState();
    void setState(bool state);
  private:
    uint8_t _pin; // light pin location
    bool _state;
    //functions
    void _reloadStates();
};

#endif
