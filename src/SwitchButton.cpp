#include "Arduino.h"
#include "SwitchButton.h"

SwitchButton::SwitchButton(int pin)
{
  _pin = pin;
  pinMode(_pin, INPUT);
  this->loop();
}
void SwitchButton::loop()
{
  _lastValue = digitalRead(_pin);
}
bool SwitchButton::isOn() {
  return (bool)_lastValue;
}
