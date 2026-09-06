# 01 - LED On

## Goal

Turn on an external LED using an ESP32 GPIO pin.

## Hardware used

- ESP32 DevKit V1
- LED
- 220 ohm resistor
- Breadboard
- Jumper wires

## Pin connections

```text
GPIO 23 -> 220 ohm resistor -> LED positive leg
LED negative leg -> GND
```

## Behavior

The ESP32 configures GPIO 23 as an output and sets it HIGH. The LED remains on
while the program is running.

## Concepts learned

- `pinMode()`
- `OUTPUT`
- `digitalWrite()`
- `HIGH` and `LOW`
