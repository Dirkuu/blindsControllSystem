echo "Connecting to Raspberry Pi Zero v1.3 and running PlatformIO remote agent..."

ssh pi@raspberrypi.local 'pio remote agent start -n raspberrypi'