#include "Arduino.h"
#include "LCD.h"
#include "ComponentsDefinitions.h"

LCD::LCD(uint8_t pin)
{
  _pin = pin;
  _currentSerial = new SoftwareSerial(_pin, -1);
}
void LCD::writeOnLine(String message, int line)
{
  _currentSerial->write(254);
  _currentSerial->write((line == 1 ? 128 : 201));
  char buf[20]; message.toCharArray(buf, 20);
  _currentSerial->write(buf);
}
