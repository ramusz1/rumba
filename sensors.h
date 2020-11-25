#include <NewPing.h>

namespace Sensors {

// Define NewPing sonar:
const int TRIGGER_PIN = 2;
const int ECHO_PIN = 3;
const int MAX_DISTANCE = 200;
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

// define other consts
const int TIME_OUT = 100;
const int DISTANCE_THRESHOLD = 20;

// Define variables
unsigned long distance=0;
unsigned long nextReadAt=0;

bool needsUpdate() {
    unsigned long time = millis();
    if (nextReadAt <= time) {
        nextReadAt = time + TIME_OUT;
        return true;
    }
    return false;
}

int getDistance() {
    if (needsUpdate()) {
        distance = sonar.ping_cm();
        Serial.print("Sensors, distance update: ");
        Serial.print(distance);
        Serial.println("cm");
    }
    return distance;
}

bool isObstacleAhead() {
    distance = getDistance();
    return distance < DISTANCE_THRESHOLD;
}

}