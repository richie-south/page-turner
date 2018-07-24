#include <elapsedMillis.h>
#include <Servo.h>
Servo myservo;
boolean isServoRunning = false;

const int echoPin = 9;
const int trigPin = 8;
long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myservo.attach(7);
}

void changePage () {
  elapsedMillis timeElapsed = 0;
  const int oneFullSpin = 1050;
  myservo.attach(7);
  myservo.write(30);

  while(timeElapsed < oneFullSpin) {
  }

  isServoRunning = false;
  myservo.detach();
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(18);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;

  if (distance < 8 && !isServoRunning) {
    isServoRunning = true;
    changePage();
  }

  delay(50);
}
