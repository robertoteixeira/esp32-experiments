# 06 - PIR Motion-Controlled LED

## Goal

Use an HC-SR501 PIR motion sensor as a digital input to control an external LED.

## Hardware used

- ESP32 DevKit V1
- HC-SR501 PIR motion sensor
- LED
- 220 ohm resistor
- Breadboard
- Jumper wires
- USB cable

## Pin connections

```text
PIR VCC -> ESP32 VIN
PIR GND -> breadboard negative rail
PIR OUT -> GPIO 27

GPIO 26 -> 220 ohm resistor -> LED positive leg
LED negative leg -> breadboard negative rail

ESP32 GND -> breadboard negative rail
```

The ESP32, PIR sensor, and LED share a common ground.

## Behavior

The LED turns on when the PIR output is HIGH and turns off when the PIR output
is LOW. The program tracks the previous sensor state so the Serial Monitor
prints `Motion detected` and `Motion stopped` only when the state changes.

The experiment initially printed the motion state continuously before state
tracking was added.

## Concepts learned

- Passive infrared sensor
- Digital sensor input
- GPIO `INPUT`
- Motion detection
- State changes
- Sensor input, decision, and output
