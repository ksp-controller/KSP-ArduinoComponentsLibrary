#include "Arduino.h"
#include "LCD.h"
#include "ComponentsDefinitions.h"

LCD::LCD(uint8_t pin)
{
  _pin = pin;
  _currentSerial = new SoftwareSerial(0, _pin);
  _currentSerial->begin(9600);
  delay(500);
  clearDisplay();
}
void LCD::writeOnLine(String message, int line)
{
  _currentSerial->write(254);
  _currentSerial->write((line == 1 ? 128 : 192));
  char buf[20]; message.toCharArray(buf, 20);
  _currentSerial->write(buf);
}
void LCD::clearDisplay() {
  _currentSerial->write(254); // move cursor to beginning of first line
  _currentSerial->write(128);
  _currentSerial->write("                "); // clear display
  _currentSerial->write("                ");
}
