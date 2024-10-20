#include <Arduino.h>

int redLED = 12;
 
int greenLED = 11;
int buzzer = 10;
int smokeSensor = 0;
int sensorThreshold = 100;

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(smokeSensor, INPUT);
  Serial.begin(9600);
}

void loop() {
  int analogSensor = analogRead(smokeSensor);

  Serial.print("Sensor Value: ");
  Serial.println(analogSensor);
  if (analogSensor > sensorThreshold) {
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);
    tone(buzzer, 1000, 200);
  } else {
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);
    noTone(buzzer);
  }
  delay(10);
}
