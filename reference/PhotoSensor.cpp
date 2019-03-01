#include "PhotoSensor.h"
#include "Arduino.h"

PhotoSensor::PhotoSensor(uint8_t pin)
{
  _pin = pin;
}
void PhotoSensor::loop()
{
  double readingValue = analogRead(_pin);
  _lastValue = (readingValue*5.0)/1024.0;
}
float PhotoSensor::getCurrentLuxValue()
{
  return _lastValue;
}
