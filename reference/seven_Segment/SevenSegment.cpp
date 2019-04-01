#include "Arduino.h"
#include "SevenSegment.h"

int startLED = 0;
int digStart = 0;

SevenSegment::SevenSegment(int sevenSegmentStart, int digitStart){
  startLED = sevenSegmentStart;
  digStart = digitStart;
  for(int i = 0; i < 8; ++i){
    pinMode(startLED + i, OUTPUT);
    digitalWrite(startLED + i, commonHigh?1:0);
  }
  for(int i = 0; i < 4; ++i){
    pinMode(digStart + i, OUTPUT);
    digitalWrite(digStart + i, HIGH);
  }  
}

void SevenSegment::fullDisplay(int num){
#define DISPLAY_TIME 5000

  long beginTime = millis();
  
  for(int digit = 1; digit <=4; digit++){

   //Selects digit
    switch(digit){
      case 1:
        digitalWrite(digStart, HIGH);
        break;
      case 2:
        digitalWrite(digStart + 1, HIGH);
        break;
      case 3:
        digitalWrite(digStart + 2, HIGH);
        break;
      case 4: 
        digitalWrite(digStart + 3, HIGH);
        break;
    }

    //Gives Digit Number
    displayDigit(num %10);
    num /= 10;

    delayMicroseconds(DISPLAY_TIME);

    displayDigit(10);

    //turn off all digits
    digitalWrite(digStart, LOW);
    digitalWrite(digStart + 1, LOW);
    digitalWrite(digStart + 2, LOW);
    digitalWrite(digStart + 3, LOW);
  }
  while((millis() - beginTime) < 10); //Wait for 20ms to pass before we paint the next digit    
}

int dig[11] = {
  0b1111110,//0
  0b0110000,//1
  0b1101101,//2
  0b1111001,//3
  0b0110011,//4
  0b1011011,//5
  0b1011111,//6
  0b1110000,//7
  0b1111111,//8
  0b1111011,//9
  0b1111111 //off
};

void SevenSegment::displayDigit(int num){
 for(int i=0;i<7;++i) {
    int currentBit = (1<<(6-i));
    int bitOn = (currentBit&dig[num])!=0;
    if(commonHigh) {
    bitOn = !bitOn;
    }
  digitalWrite(startLED + i, bitOn);
  } 
}