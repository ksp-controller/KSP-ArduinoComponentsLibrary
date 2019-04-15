#include "Arduino.h"
#include "LightController.h"
#include "ComponentsDefinitions.h"

LightController::LightController(uint8_t pin)
{
  //init pins
  pinMode(pin, OUTPUT);
  //set default states
  _pin = pin;
  _state = false;
  // reload current state
  this->_reloadStates();
}
bool LightController::getState()
{
  return _state;
}
void LightController::setState(bool state) {
  _state = state;
  _reloadStates();
}

void LightController::_reloadStates()
{
    digitalWrite(_pin, (_state ? HIGH : LOW));
}
