#include <Stepper.h>

namespace Steppers{

const int stepsPerRevolution = 2048;
int stepsPerTick = 10;
int speed = 15;

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

Stepper stepper1 = Stepper(stepsPerRevolution, Stpr1::pin1, Stpr1::pin2, Stpr1::pin3, Stpr1::pin4);
Stepper stepper2 = Stepper(stepsPerRevolution, Stpr2::pin1, Stpr2::pin2, Stpr2::pin3, Stpr2::pin4);

void setup() {
    Serial.println("Starting steppers setup");

    stepper1.setSpeed(speed);
    stepper2.setSpeed(speed);
    
    Serial.println("Finished steppers setup");
}

void forward() {
    stepper1.step(-stepsPerTick);
    stepper2.step(stepsPerTick);
}

void left() {
    stepper1.step(stepsPerTick);
    stepper2.step(stepsPerTick);
}

void right() {
    stepper1.step(-stepsPerTick);
    stepper2.step(-stepsPerTick);
}

}
