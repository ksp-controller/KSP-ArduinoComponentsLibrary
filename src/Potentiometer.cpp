#include "Arduino.h"
#include "Potentiometer.h"
#include "ComponentsDefinitions.h"

Potentiometer::Potentiometer(uint8_t pin, int min, int max)
{
  _pin = pin;
  _min = min;
  _max = max;
  pinMode(_pin, INPUT);
  this->loop();
}
void Potentiometer::loop()
{
  int readingValue = analogRead(_pin);
  _lastValue = min(max(map(readingValue, POTEN_MIN, POTEN_MAX, _min, _max), _min), _max);
}
int Potentiometer::getCurrentValue()
{
  return _lastValue;
}
