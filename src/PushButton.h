#ifndef PushButton_h
#define PushButton_h
#include "Arduino.h"

class PushButton
{
  public:
    PushButton(uint8_t pin);
    void loop();
    bool isPressed();
  private:
    uint8_t _pin; //green light pin location
    boolean _lastValue; //last read value
    unsigned long _lastPositiveRead;
};
#endif
