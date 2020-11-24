
#include "sensors.h"

// VARIABLES
unsigned long timer = 0;

void setup() {
    // Begin Serial communication at a baudrate of 9600:
    Serial.begin(9600);
}

void loop() {
    // READ SENSORS:
    if (Sensors::needsUpdate()) {
        Sensors::getDistance();
    }
    //TODO
  
    // CONTROLL MOTORS
    // TODO

    delay(1);
}