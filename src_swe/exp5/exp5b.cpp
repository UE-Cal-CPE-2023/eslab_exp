#include <Arduino.h>
#include "pitches.h"

const int speaker = 9;
const int ldr = 0;

void setup() {
    Serial.begin(9600);
    pinMode(speaker, OUTPUT);
}
void loop() {
    // calibrate the sensor:
    int maxVal = 1000; //Change this value depending on the sensor reading
    int minVal = 400; //Change this value depending on the sensor reading
    int sensorReading = analogRead(ldr);
    Serial.println(sensorReading);
    int thisPitch = map(sensorReading, minVal, maxVal, 120, 1500);
    tone(speaker, thisPitch, 10);
    delay(10);        
}