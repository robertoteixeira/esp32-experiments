#include <Arduino.h>

const int ledPin = 23;
const int buttonPin = 22;
const unsigned long debounceDelay = 50;

int lastButtonState = HIGH;
int buttonState = HIGH;
bool isLedOn = false;

unsigned long lastDebounceTime = 0;

void setup() {
    pinMode(ledPin, OUTPUT);
    pinMode(buttonPin, INPUT_PULLUP);

    digitalWrite(ledPin, LOW);
}

void loop() {
    int reading = digitalRead(buttonPin);

    if (reading != lastButtonState) {
        lastDebounceTime = millis();
    }

    if (millis() - lastDebounceTime >= debounceDelay) {
        if (reading != buttonState) {
            buttonState = reading;

            // Toggle only on a debounced press; releasing keeps the LED state.
            if (buttonState == LOW) {
                isLedOn = !isLedOn;
                digitalWrite(ledPin, isLedOn ? HIGH : LOW);
            }
        }
    }

    lastButtonState = reading;
}
