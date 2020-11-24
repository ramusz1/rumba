#include <AccelStepper.h>

namespace Steppers{

const int8_t fullStep = 4;
const int fullRevolutionSteps = 2038;
int maxSpeed = 1000;
int speed = 100;
int acceleration = 200;

// Stepper pin mapping:
// pin1: IN1
// pin3: IN2
// pin2: IN3
// pin4: IN4
namespace Stpr1{
    const int8_t pin1 = 8;
    const int8_t pin2 = 10;
    const int8_t pin3 = 9;
    const int8_t pin4 = 11;
}

namespace Stpr2{
    const int8_t pin1 = 4;
    const int8_t pin2 = 6;
    const int8_t pin3 = 5;
    const int8_t pin4 = 7;
}

AccelStepper stepper1 = AccelStepper(fullStep, Stpr1::pin1, Stpr1::pin2, Stpr1::pin3, Stpr1::pin4);
AccelStepper stepper2 = AccelStepper(fullStep, Stpr2::pin1, Stpr2::pin2, Stpr2::pin3, Stpr2::pin4);

void setup() {
    Serial.println("Starting steppers setup");

    stepper1.setMaxSpeed(maxSpeed);
    stepper1.setAcceleration(acceleration);
    stepper1.setSpeed(speed);
    stepper1.moveTo(fullRevolutionSteps);

    stepper2.setMaxSpeed(maxSpeed);
    stepper2.setAcceleration(acceleration);
    stepper2.setSpeed(speed);
    stepper2.moveTo(fullRevolutionSteps);

    Serial.println("Finished steppers setup");
}

void action() {
   stepper1.run();
   stepper2.run();
}

}
