#include <Arduino.h>
#include "pitches.h"

const int speaker = 9;
int melody[] = {NOTE_A6, NOTE_FS6, NOTE_G6, NOTE_A6, NOTE_FS6, NOTE_G6, NOTE_A6, NOTE_A5, NOTE_B5, NOTE_CS6, NOTE_D6, NOTE_E6, NOTE_FS6, NOTE_G6, NOTE_FS6, NOTE_D6, NOTE_E6, NOTE_FS6, NOTE_FS5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_A5, NOTE_G5, NOTE_A5, NOTE_FS5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_B5, NOTE_A5, NOTE_G5, NOTE_FS5, NOTE_E5, NOTE_FS5, NOTE_E5, NOTE_D5, NOTE_E5, NOTE_FS5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_G5, NOTE_B5, NOTE_A5, NOTE_B5, NOTE_CS6, NOTE_D6, NOTE_A5, NOTE_B5, NOTE_CS6, NOTE_D6, NOTE_E6, NOTE_FS6, NOTE_G6, NOTE_A6};
int noteDurations[] = {8, 16, 16, 8, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 8, 16, 16, 8, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 8, 16, 16, 8, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 8, 16, 16, 8, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16};

void setup() {
    pinMode(speaker,OUTPUT);    
    for (int i = 0; i < 56; i++) {          
        int noteDuration = 2500 / noteDurations[i];       
        tone(speaker, melody[i], noteDuration);       
        int pauseBetweenNotes = noteDuration * 1.30;      
        delay(pauseBetweenNotes);
    }
}

void loop() {
    // no need to repeat the melody.
}