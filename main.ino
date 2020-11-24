
#include "sensors.h"
#include "steppers.h"

// VARIABLES
unsigned long timer = 0;

void setup() {
    Steppers::setup();

    //Begin Serial communication at a baudrate of 9600:
    Serial.begin(9600);
}

void loop() {
    // READ SENSORS:
    if (Sensors::needsUpdate()) {
        Sensors::getDistance();
    }
  
    // CONTROLL MOTORS
    Steppers::action();

    delay(1);
}