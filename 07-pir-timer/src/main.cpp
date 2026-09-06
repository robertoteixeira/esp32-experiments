#include <Arduino.h>

const int ledPin = 26;
const int pirPin = 27;

unsigned long motionDetectedTime = 0;
const unsigned long ledOnDuration = 5000;

bool ledIsOn = false;

void setup() {
    Serial.begin(115200);

    pinMode(ledPin, OUTPUT);
    pinMode(pirPin, INPUT);

    digitalWrite(ledPin, LOW);
}

void loop() {
    int motionState = digitalRead(pirPin);

    if (motionState == HIGH) {
        motionDetectedTime = millis();

        if (!ledIsOn) {
            digitalWrite(ledPin, HIGH);
            ledIsOn = true;

            Serial.println("Motion detected - LED ON");
        }
    }

    if (ledIsOn &&
        millis() - motionDetectedTime >= ledOnDuration) {

        digitalWrite(ledPin, LOW);
        ledIsOn = false;

        Serial.println("LED OFF after 5 seconds");
    }
}
