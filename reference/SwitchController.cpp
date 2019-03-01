#include "Arduino.h"
#include "SwitchController.h"

SwitchController::SwitchController(int rPin, int confPin, int confPin2, IntersectionController* delegate)
{
  _rPin = rPin;
  _rPreviousValue = -1;
  _confPin = confPin;
  _confPreviousValue = -1;
  _confPin2 = confPin2;
  _conf2PreviousValue = -1;
  _delegate = delegate;
  //Initialize
  pinMode(_rPin, INPUT);
  pinMode(_confPin, INPUT);
  pinMode(_confPin2, INPUT);
  //Go for read
  _readNewValues();
}
void SwitchController::loop()
{
  _readNewValues();
}

void SwitchController::_readNewValues()
{
    //Read reset button
    int _rRead = digitalRead(_rPin);
    if (_rPreviousValue != _rRead) {
      _rPreviousValue = _rRead;
      _delegate->changeIntersectionLockState((bool) _rRead);
    }


    bool anyConfChanges = false;
    //Read conf button
    int _confRead = digitalRead(_confPin);
    if (_confPreviousValue != _confRead) {
      _confPreviousValue = _confRead;
      anyConfChanges = true;
    }
    //Read conf2 button
    int _conf2Read = digitalRead(_confPin2);
    if (_conf2PreviousValue != _conf2Read) {
      _conf2PreviousValue = _conf2Read;
      anyConfChanges = true;
    }
    if (anyConfChanges) {
      //Generate struct from conf
      IntersectionParameters params = IntersectionParamFromConfs(_confRead, _conf2Read);
      _delegate->changeIntersectionTimingParameters(params);
    }
}
