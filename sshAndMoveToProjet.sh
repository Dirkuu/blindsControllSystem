echo "Connecting to Raspberry Pi Zero v1.3 and moving to project"

ssh -t pi@raspberrypi.local 'cd .platformio/remote/projects/blindsControllSystem-a270441a81415f785414fbe1a174c22ae747011a/.pio/build/raspberrypi_zero; bash -l'