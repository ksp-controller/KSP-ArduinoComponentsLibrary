#include "Arduino.h"
#include "PushButton.h"
#include "ComponentsDefinitions.h"

PushButton::PushButton(uint8_t pin)
{
  _pin = pin;
  _needsRead = true;
  pinMode(_pin, INPUT);
  this->loop();
}
void PushButton::loop()
{
  _lastValue = digitalRead(_pin);
  if (!_lastValue && !_needsRead) _needsRead = true;
}
bool PushButton::isPressed()
{
  if (_lastValue && !_needsRead) return false; //debounce
  if (_lastValue) _needsRead = false; //ask for debounce on next loop if state still true
  return _lastValue;
}
