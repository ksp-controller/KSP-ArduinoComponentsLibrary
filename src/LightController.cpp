#include "Arduino.h"
#include "LightController.h"
#include "Definitions.h"

LightController::LightController(uint8_t pin)
{
  //init pins
  pinMode(pin, OUTPUT);
  //set default states
  _pin = pin;
  _blinkStamp = millis();
  _blinkState = ON_BLINK;
  _state = OFF;
  // reload current state
  _reloadStates();
}
void LightController::loop()
{
  _blink();
}
int LightController::getState()
{
  return _state;
}
void LightController::setState(int state) {
  _state = state;
  _reloadStates();
}

void LightController::_reloadStates()
{
    int lightState = (_state == BLINK ? _blinkState : _state);
    analogWrite(_pin, lightState);
}
void LightController::_blink()
{
  //return if invalid state
  if (_state != BLINK)
    return;
  //
  if (millis() - _blinkStamp >= LightBlinkInterval) {
    _blinkStamp = millis();
    _blinkState = SwapStates(_blinkState);
    analogWrite(_pin, _blinkState);
  }
}
