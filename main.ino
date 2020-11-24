
#include "sensors.h"
#include "steppers.h"

void setup() {
    Steppers::setup();

    //Begin Serial communication at a baudrate of 9600:
    Serial.begin(9600);
}

void loop() {
    // READ SENSORS:
    bool wallAhead = Sensors::isObstacleAhead();
  
    // CONTROLL MOTORS
    Steppers::action();

    delay(1);
}