#include <Arduino.h>

const int ledPin = 23;
const unsigned long interval = 500;

unsigned long previousTime = 0;
bool isLedOn = false;

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
}

void loop() {
  unsigned long currentTime = millis();

  if (currentTime - previousTime >= interval) {
    previousTime = currentTime;
    isLedOn = !isLedOn;
    digitalWrite(ledPin, isLedOn ? HIGH : LOW);
  }
}