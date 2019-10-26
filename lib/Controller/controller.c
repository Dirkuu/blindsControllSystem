#ifndef BLINDS_CONTROLLER
#define BLINDS_CONTROLLER


#include <wiringPi.h>
#include <unistd.h>
#include <stdio.h>

#include <string.c>

#include <light.c>
#include <hall.c>
#include <temperature.c>


#define lightPin            1
#define topHallPin          4
#define bottomHallPin       404
#define temperaturePin      29

#define refreshFrequency    10
#define preferTemp          22


#define UP                  1
#define DOWN                -1

int currentState = DOWN;
int currentTemp = -1;










int tryGoUp() {
    if (currentState != UP && isLight(lightPin)) {
        while (!isMagnetClose(topHallPin)) {
            printf("Do góry\n");
            sleep(1);
        }
        printf("Dotarliśmy na górę\n\n");

        currentState = UP;
        currentTemp = 1;

        return 0;
    }
    else if (currentState == UP) {
        printf("Jesteśmy już na górze, cieplej nie będzie\n\n");
        return -1;
    }
    else if (!isLight(lightPin)) {
        printf("Na zewnątrz jest ciemno, nie ma sensu podnosić rolety :/\nNapal więcej w piecu\n\n");
        return -2;
    }
}




void init() {
    if (wiringPiSetup() == -1) {
        printf("Niepoprawna instalacja WiringPi\n");
        return -1;
    }


    pinMode(lightPin, INPUT);
    pinMode(topHallPin, INPUT);
    pinMode(temperaturePin, INPUT);
}

void controller() {
    init();

    while (1) {
        switch (currentTemp) {
            case -1:
                printf("Rolety do góry, jest za zimno\n");
                tryGoUp();
                break;
            case 1:
                printf("Rolety w dół, jest za ciepło\n");

                sleep(2);
                currentState = DOWN;
                currentTemp = -1;
                printf("Rolety na dole\n\n");

                break;
            case 0:
                printf("Wszystko w porządku, nic nie robimy\n");
                break;

            default:
                return;
        }


        sleep(refreshFrequency);
    }
}










#endif