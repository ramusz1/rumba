namespace Sensors{

// Define Trig and Echo pin:
int trigPin = 2;
int echoPin = 3;

// Define variables:
long duration=0;
int distance=0;

void setup() {
  // Define inputs and outputs:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void action() {
  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.println(" cm");
}

} //namespace Sensors