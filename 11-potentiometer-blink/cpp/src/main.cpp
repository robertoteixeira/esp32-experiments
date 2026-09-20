#include <Arduino.h>

const int ledPin = 23;
const int potentiometerPin = 34;

unsigned long previousTime = 0;
bool isLedOn = false;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(potentiometerPin, INPUT);
  digitalWrite(ledPin, LOW);

  analogReadResolution(12);
}

void loop() {
  int reading = analogRead(potentiometerPin);
  unsigned long interval = map(reading, 0, 4095, 100, 1000);

  unsigned long currentTime = millis();

  if (currentTime - previousTime >= interval) {
    previousTime = currentTime;
    isLedOn = !isLedOn;
    digitalWrite(ledPin, isLedOn ? HIGH : LOW);
  }
}