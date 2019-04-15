#ifndef LCD_h
#define LCD_h
#include "Arduino.h"
#include <SoftwareSerial.h>

class LCD
{
  public:
    LCD(uint8_t pin);
    void writeOnLine(String message, int line); //1 - first, 2 - second
    void clearDisplay();
  private:
    uint8_t _pin;
    SoftwareSerial* _currentSerial;
};
#endif
