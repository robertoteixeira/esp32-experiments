#include <Arduino.h>

const int ledPin = 23;
const int buttonPin = 22;

void setup() {
    Serial.begin(115200);

    pinMode(ledPin, OUTPUT);
    pinMode(buttonPin, INPUT_PULLUP);

    digitalWrite(ledPin, LOW);
}

void loop() {
    int buttonState = digitalRead(buttonPin);

    if (buttonState == LOW) {
        digitalWrite(ledPin, HIGH);
        Serial.println("Button pressed");
    } else {
        digitalWrite(ledPin, LOW);
        Serial.println("Button released");
    }
}
