#ifndef PINS
#define PINS


#include <stdbool.h>


bool isDigitalPinHigh(int pin) {
    if (digitalRead(pin) == 1)  return true;
    
    return false;
}


#endif