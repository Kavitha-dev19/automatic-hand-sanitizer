#include <Servo.h>

Servo servo;
const int trigPin = 9;
const int echoPin = 10;

void setup() {
  servo.attach(6);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  long distance = getDistance();
  if (distance < 10) {
    servo.write(90);
    delay(1000);
    servo.write(0);
    delay(2000);
  }
}

long getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2;
}
