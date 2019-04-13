#ifndef SwitchController_h
#define SwitchController_h
//
#include "Arduino.h"
//
class SwitchController
{
  public:
    SwitchController(int rPin, int confPin, int confPin2);
    void loop(); //should be called every arduino loop
  private:
    int _rPin, _rPreviousValue;
    int _confPin, _confPreviousValue;
    int _confPin2, _conf2PreviousValue;
    void _readNewValues();
};

#endif
