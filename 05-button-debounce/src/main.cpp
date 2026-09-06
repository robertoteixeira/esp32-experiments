#include <Arduino.h>

const int ledPin = 23;
const int buttonPin = 22;

int lastButtonState = HIGH;
int buttonState = HIGH;

unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;

void setup() {
    Serial.begin(115200);

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

            if (buttonState == LOW) {
                digitalWrite(ledPin, HIGH);
                Serial.println("Button pressed");
            } else {
                digitalWrite(ledPin, LOW);
                Serial.println("Button released");
            }
        }
    }

    lastButtonState = reading;
}
