#ifndef HALL
#define HALL


#include <pins.c>


bool isMagnetClose(int pin) {
    return isDigitalPinHigh(pin);
}


#endif