#include "Arduino.h"
#include "Joystick.h"
#include "ComponentsDefinitions.h"

Joystick::Joystick(uint8_t lPin, uint8_t rPin, uint8_t tPin, uint8_t bPin, int min, int max)
{
  _lPin = lPin; _rPin = rPin;
  _tPin = tPin; _bPin = bPin;
  _min = min; _max = max;
  pinMode(_lPin, INPUT);
  pinMode(_rPin, INPUT);
  pinMode(_tPin, INPUT);
  pinMode(_bPin, INPUT);
  this->loop();
}
void Joystick::loop()
{
  _lastValue = {
    min(max(map(analogRead(_lPin), JOY_MIN, JOY_MAX, _min, _max), _min), _max),
    min(max(map(analogRead(_rPin), JOY_MIN, JOY_MAX, _min, _max), _min), _max),
    min(max(map(analogRead(_tPin), JOY_MIN, JOY_MAX, _min, _max), _min), _max),
    min(max(map(analogRead(_bPin), JOY_MIN, JOY_MAX, _min, _max), _min), _max)
  };
}
JoystickValue Joystick::getCurrentValue()
{
  return _lastValue;
}
