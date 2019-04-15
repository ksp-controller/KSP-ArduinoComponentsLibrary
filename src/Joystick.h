#ifndef Joystick_h
#define Joystick_h
#include "Arduino.h"

typedef struct JoystickValue {
  int leftValue;
  int rightValue;
  int topValue;
  int bottomValue;
};

class Joystick
{
  public:
    Joystick(uint8_t lPin, uint8_t rPin, uint8_t tPin, uint8_t bPin, int min, int max);
    void loop();
    JoystickValue getCurrentValue();
  private:
    uint8_t _lPin, _rPin, _tPin, _bPin;
    int _min, _max;
    JoystickValue _lastValue; //last read value
};
#endif
