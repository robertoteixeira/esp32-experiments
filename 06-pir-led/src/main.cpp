#include <Arduino.h>

const int ledPin = 26;
const int pirPin = 27;

int lastMotionState = LOW;

void setup() {
    Serial.begin(115200);

    pinMode(ledPin, OUTPUT);
    pinMode(pirPin, INPUT);

    digitalWrite(ledPin, LOW);
}

void loop() {
    int motionState = digitalRead(pirPin);

    if (motionState != lastMotionState) {
        if (motionState == HIGH) {
            digitalWrite(ledPin, HIGH);
            Serial.println("Motion detected");
        } else {
            digitalWrite(ledPin, LOW);
            Serial.println("Motion stopped");
        }

        lastMotionState = motionState;
    }
}
