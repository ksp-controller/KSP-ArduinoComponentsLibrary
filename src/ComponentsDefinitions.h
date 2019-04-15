#ifndef ComponentsDefinitions_h
#define ComponentsDefinitions_h
#include "Arduino.h"

#define LightBlinkInterval 200
#define OFF 0 //definition of a OFF LIGHT
#define ON 255 //definition of a ON LIGHT
#define BLINK 254
#define ON_BLINK 255 //definition of a ON BLINKING LIGHT
#define OFF_BLINK 5 //definition of a OFF BLINKING LIGHT
#define SwapStates(current) (current == ON_BLINK ? OFF_BLINK : ON_BLINK)
//Potentiometer
#define POTEN_MIN 30 //leave gap
#define POTEN_MAX 1010 //leave gap
//Joystick
#define JOY_MIN 120
#define JOY_MAX 950
//LCD
#define LCD_BAUDRATE 9600
#endif
