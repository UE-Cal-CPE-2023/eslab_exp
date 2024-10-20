#include <Arduino.h>

int inPin = 2;
int LEDstate = HIGH;     
int reading;
int previous = LOW;    
long time = 0;
long debounce = 50;
 
void setup() {
  pinMode(inPin, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}
 
void loop() {
  int switchstate;
 
  reading = digitalRead(inPin);
  if (reading != previous) {
    time = millis();
  } 
 
  if ((millis() - time) > debounce) {
     switchstate = reading;
    if (switchstate == HIGH)
      LEDstate = LOW;
    else
      LEDstate = HIGH;
  }
  digitalWrite(LED_BUILTIN, LEDstate);
  previous = reading;
}
