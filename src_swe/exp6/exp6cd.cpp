#include <Arduino.h>
#include <Servo.h>

Servo myServo;
const int servoPin = 3;
const int sensorPin = A0;
int val;

void setup() {
    myServo.attach(servoPin);
}

void loop() {
    val = analogRead(sensorPin);
    val = map(val, 0, 1023, 0, 179); //adjust the max and min value of the LDR to satisfy room lighting conditions
    myServo.write(val); delay(15);
}