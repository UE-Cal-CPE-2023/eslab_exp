#include <Arduino.h>
#include "pitches.h"

const int speaker = 9;
int notes[] = {NOTE_A1, NOTE_E5, NOTE_FS7};

void setup() {
    pinMode(speaker, OUTPUT);
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
}

void loop() {
    for (int thisSensor = 2; thisSensor < 5; thisSensor++) {
        if (digitalRead(thisSensor)) {
            tone(speaker, notes[thisSensor]);
        } 
        noTone(speaker);
    }
}