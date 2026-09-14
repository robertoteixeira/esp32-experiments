# 08 - Non-blocking LED Blink

## Goal

Blink an LED without pausing the program with `delay()`.

## Hardware and wiring

Use an ESP32 DevKit V1, breadboard, LED, 220 ohm resistor, and jumper wires.

```text
GPIO 23 -> 220 ohm resistor -> LED positive (long leg)
LED negative (short leg) -> GND
```

## Behavior

The LED starts off and changes state every 500 milliseconds: half a second off,
half a second on. A complete cycle lasts one second. The loop keeps running
between changes.

## Concepts learned

- Non-blocking timing with `millis()`
- Elapsed-time subtraction
- Tracking and toggling a Boolean LED state

## Implementations

- [C++ source](cpp/src/main.cpp) — Arduino framework with PlatformIO.
- Rust — planned; no implementation yet.

## Build and upload C++

Open this experiment's `cpp/` folder in VS Code. See the
[C++ setup guide](../docs/cpp-setup.md) for prerequisites and editor setup.

From the repository root:

```sh
pio run -d 08-non-blocking-blink/cpp
pio run -d 08-non-blocking-blink/cpp -t upload
```
