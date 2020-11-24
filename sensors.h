#include <NewPing.h>

namespace Sensors{

// Define sonar:
const int TRIGGER_PIN = 2;
const int ECHO_PIN = 3;
const int MAX_DISTANCE = 200;
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

// define namespace consts
const int TIME_OUT = 200;

// Define variables:
int distance=0;
int nextReadAt=0;

bool needsUpdate() {
    long time = millis();
    if (nextReadAt <= time) {
        nextReadAt += time + TIME_OUT;
        return true;
    }
    return false;
}

void getDistance() {
    distance = sonar.ping_cm();
    Serial.print("Ping: ");
    Serial.print(distance);
    Serial.println("cm");
}

} //namespace Sensors