#include <Arduino.h>
#include "pitches.h"

const int speaker = 9;
int notes[] = {0, 0, NOTE_A1, NOTE_E5, NOTE_FS7};

void setup() {
    pinMode(speaker, OUTPUT);
    pinMode(2, INPUT);
    pinMode(3, INPUT);
    pinMode(4, INPUT);
}

void loop() {
    for (int thisSensor = 2; thisSensor < 5; thisSensor++) {
        if (digitalRead(thisSensor)) {
            tone(speaker, notes[thisSensor]);
        }
        noTone(speaker);
    }
}