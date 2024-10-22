#include <Arduino.h>
#include <Stepper.h>

const int stepsPerRevolution = 200; // change this to fit the number of steps per revolution for your motor
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);
int stepCount = 0;

void setup() {
}

void loop() {
    int sensorReading = analogRead(A0);
    int motorSpeed = map(sensorReading, 0, 1023, 0, 100);
    if (motorSpeed > 0) {
        myStepper.setSpeed(motorSpeed);
        myStepper.step(stepsPerRevolution / 100);
    }
}