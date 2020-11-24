
#include "sensors.h"
#include "steppers.h"

// CONSTS

void setup() {
  // nothing to do inside the setup
  Sensors::setup();
  Steppers::setup();

  //Begin Serial communication at a baudrate of 9600:
  Serial.begin(9600);
}

void loop() {
  // READ SENSORS:
  Sensors::action();
  //TODO
  
  // CONTROLL MOTORS
  Steppers::action();
  // TODO


  delay(1);
}