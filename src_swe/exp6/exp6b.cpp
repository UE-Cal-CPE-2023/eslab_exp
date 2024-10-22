#include <Arduino.h>
#include <Servo.h>

Servo myServo;
const int servoPin = 9;

void setup() {
    myServo.attach(servoPin);
}

void loop() {
    for (int i = 1000; i <= 2000; i++) {
        myServo.writeMicroseconds(i);
    }
    delay(2000);
    for (int i = 2000; i >= 1000; i--) {
        myServo.writeMicroseconds(i);
    }
    delay(2000);
}