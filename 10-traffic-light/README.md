# 10 - Traffic Light with Pedestrian Button

## Goal

Run a button-triggered traffic-light sequence without blocking the program.

## Hardware and wiring

Use an ESP32 DevKit V1, breadboard, red/yellow/green LEDs, three 220 ohm
resistors (one per LED), a push button, and jumper wires.

| Connection | Wiring |
|---|---|
| Green LED | GPIO 23 -> 220 ohm resistor -> positive (long leg) |
| Yellow LED | GPIO 25 -> 220 ohm resistor -> positive (long leg) |
| Red LED | GPIO 26 -> 220 ohm resistor -> positive (long leg) |
| All LED negative (short) legs | Common GND rail |
| Button | GPIO 22 -> push button -> common GND rail |
| Common GND rail | ESP32 GND |

Disconnect USB while wiring. Use one uninterrupted section of the breadboard
rail for ground. The button uses `INPUT_PULLUP` and needs no external resistor.

## Behavior

Green is on at startup. An accepted button press switches to yellow for two
seconds, then red for five seconds, then back to green. Only one LED is on at a
time. Presses during yellow or red are ignored, not queued. Holding the button
does not request another crossing; release and press again. Button changes are
debounced for 50 milliseconds.

## Concepts learned

- An enum-based state machine
- Non-blocking timed transitions
- Combining debounced input with multiple outputs

## Implementations

- [C++ source](cpp/src/main.cpp) — Arduino framework with PlatformIO.
- Rust — planned; no implementation yet.

## Build and upload C++

Open this experiment's `cpp/` folder in VS Code. See the
[C++ setup guide](../docs/cpp-setup.md) for prerequisites and editor setup.

From the repository root:

```sh
pio run -d 10-traffic-light/cpp
pio run -d 10-traffic-light/cpp -t upload
```
