#ifndef PushButton_h
#define PushButton_h
  #include "Arduino.h"
  #include "Definitions.h"

class PushButton
  {
  private:
    uint8_t _pin; //green light pin location
    boolean _lastValue; //last read value
  public:
    PushButton::PushButton(uint8_t pin)
    {
      _pin = pin;
      pinMode(_pin, INPUT);
    }
    void PushButton::loop()
    {
      _lastValue = digitalRead(_pin);
    }
    boolean PushButton::isPressed()
    {
      return _lastValue;
    }
  };
#endif
