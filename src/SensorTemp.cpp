#include "SensorTemp.h"
#include "Arduino.h"

SensorTemp::SensorTemp(uint8_t pin)
{
  _pin = pin;
}
void SensorTemp::loop()
{
  double readingValue = analogRead(_pin);
  _lastValue = (readingValue*5.0)/1024.0;
}
float SensorTemp::getCurrentCValue()
{
  return (_lastValue - 0.5) * 100.0;
}
float SensorTemp::getCurrentFValue()
{
  return (getCurrentCValue() * 9.0 / 5.0) + 32.0;
}
