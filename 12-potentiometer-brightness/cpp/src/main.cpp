#include <Arduino.h>

const int ledPin = 23;
const int potentiometerPin = 34;

void setup() {
    pinMode(potentiometerPin, INPUT);
    analogReadResolution(12);

    ledcSetup(0, 5000, 8);   // Channel 0, 5 kHz, 8-bit brightness
    ledcAttachPin(ledPin, 0);
    ledcWrite(0, 128);       // Fixed 50% duty cycle for this test
}

void loop() {
    int reading = analogRead(potentiometerPin);
    int brightness = map(reading, 0, 4095, 0, 255);

    ledcWrite(0, brightness);
}