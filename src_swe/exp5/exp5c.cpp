#include <Arduino.h>
#include "pitches.h"

const int threshold = 10;
const int speaker = 9;
int notes[] = {NOTE_A1, NOTE_E5, NOTE_FS7};

void setup() {
    pinMode(speaker,OUTPUT);
}

void loop() {
    for (int thisSensor = 0; thisSensor < 3; thisSensor++) {
        int sensorReading = analogRead(thisSensor);
        if (sensorReading > threshold) {
            tone(speaker, notes[thisSensor]);
        } 
        noTone(speaker);
    }
}