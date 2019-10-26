#ifndef LIGHT
#define LIGHT


#include <pins.c>


bool isLight(int pin) {
    return !isDigitalPinHigh(pin);
}


#endif