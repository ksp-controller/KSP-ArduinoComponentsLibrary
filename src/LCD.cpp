#include "Arduino.h"
#include "LCD.h"
#include "ComponentsDefinitions.h"

LCD::LCD(uint8_t pin)
{
  _pin = pin;
  _currentSerial = new SoftwareSerial(0, _pin);
  _currentSerial->begin(LCD_BAUDRATE);
  delay(500);
  // ESP8266 internal cache RAM needs warm up - allow write and ISR to load
  _currentSerial->write(static_cast<uint8_t>(0));
  for (char ch = ' '; ch <= 'z'; ch++) _currentSerial->write(ch);
  _currentSerial->println("");
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
