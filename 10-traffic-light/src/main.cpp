#include <Arduino.h>

const int greenLedPin = 23;
const int yellowLedPin = 25;
const int redLedPin = 26;
const int buttonPin = 22;

enum TrafficState { GREEN, YELLOW, RED };

TrafficState trafficState = GREEN;

unsigned long stateStartedTime = 0;
unsigned long lastDebounceTime = 0;

const unsigned long debounceDelay = 50;
const unsigned long yellowDuration = 2000;
const unsigned long redDuration = 5000;

int lastButtonState = HIGH;
int buttonState = HIGH;

void setup() {
  pinMode(greenLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  digitalWrite(greenLedPin, HIGH);
  digitalWrite(yellowLedPin, LOW);
  digitalWrite(redLedPin, LOW);
}

void loop() {
  int reading = digitalRead(buttonPin);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if (millis() - lastDebounceTime >= debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;

      if (buttonState == LOW && trafficState == GREEN) {
        trafficState = YELLOW;
        stateStartedTime = millis();

        digitalWrite(greenLedPin, LOW);
        digitalWrite(yellowLedPin, HIGH);
      }
    }
  }

  lastButtonState = reading;

  unsigned long currentTime = millis();

  if (trafficState == YELLOW &&
      currentTime - stateStartedTime >= yellowDuration) {

    trafficState = RED;
    stateStartedTime = currentTime;

    digitalWrite(yellowLedPin, LOW);
    digitalWrite(redLedPin, HIGH);
  } else if (trafficState == RED &&
             currentTime - stateStartedTime >= redDuration) {

    trafficState = GREEN;
    stateStartedTime = currentTime;

    digitalWrite(redLedPin, LOW);
    digitalWrite(greenLedPin, HIGH);
  }
}
