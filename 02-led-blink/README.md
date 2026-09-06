# 02 - LED Blink

## Goal

Make an external LED blink by repeatedly changing an ESP32 GPIO output.

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

The ESP32 turns the LED on, waits 200 milliseconds, turns it off, and waits
another 200 milliseconds. This repeats continuously.

The experiment initially used 1000 millisecond delays before the delay was
changed to 200 milliseconds to observe a faster blink rate.

## Concepts learned

- `loop()`
- `digitalWrite()`
- `delay()`
- Milliseconds
