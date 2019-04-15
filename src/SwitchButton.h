#ifndef SwitchButton_h
#define SwitchButton_h
#include "Arduino.h"
//
class SwitchButton
{
  public:
    SwitchButton(int pin);
    void loop(); //should be called every arduino loop
    bool isOn(); //
  private:
    int _pin, _lastValue;
};
#endif
