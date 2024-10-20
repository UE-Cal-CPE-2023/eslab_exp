#include <Arduino.h>

const int sensorPin = A0;
const int ledPin = 9;
int sensorValue = 0;
int sensorMin = 1023;
int sensorMax = 0;

void setup() {
    pinMode(13, OUTPUT);
    digitalWrite(13, HIGH);
    Serial.begin(9600);

    while (millis() < 3000) {
        sensorValue = analogRead(sensorPin);
        if (sensorValue > sensorMax) {
            sensorMax = sensorValue;
        }
        if (sensorValue < sensorMin) {
            sensorMin = sensorValue;
        }
    }
    digitalWrite(13, LOW);
}

void loop() {
    sensorValue = analogRead(sensorPin);
    sensorValue = map(sensorValue, sensorMin, sensorMax, 0, 255);
    sensorValue = constrain(sensorValue, 0, 255);
    Serial.println(sensorValue);
    analogWrite(ledPin, sensorValue);
    delay(10);
}
