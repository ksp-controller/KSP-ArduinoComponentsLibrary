#include "Arduino.h"
#include "PushButton.h"
#include "ComponentsDefinitions.h"

PushButton::PushButton(uint8_t pin)
{
  _pin = pin;
  pinMode(_pin, INPUT);
  _lastPositiveRead = millis(); //dont allow prompt position read
  this->loop();
}
void PushButton::loop()
{
  _lastValue = (digitalRead(_pin) == 1);
  if (_lastValue && millis() - _lastPositiveRead < PUSHBUTTON_DELAY) _lastValue = false;
}
bool PushButton::isPressed()
{
  if (_lastValue) {
    _lastValue = false; //ask for debounce on next loop if state still true
    _lastPositiveRead = millis();
    return true;
  } return false;
}
