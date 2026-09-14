# 05 - Button Debounce

## Goal

Prevent a mechanical push button from producing multiple press and release
events from a single physical action.

## Hardware used

- ESP32 DevKit V1
- Push button
- LED
- 220 ohm resistor
- Breadboard
- Jumper wires
- USB cable

## Pin connections

```text
GPIO 23 -> 220 ohm resistor -> LED positive leg
LED negative leg -> GND

GPIO 22 -> push button -> GND
```

GPIO 22 uses the ESP32's internal pull-up resistor.

## Behavior

The button reads HIGH when released and LOW when pressed. The program waits
until a changed input has remained stable for 50 milliseconds before accepting
it as the new button state.

An accepted press turns the LED on and prints `Button pressed`. An accepted
release turns the LED off and prints `Button released`.

The experiment first tested a simple `delay(50)` before switching to the final
non-blocking implementation using `millis()`.

## Concepts learned

- Mechanical button bounce
- Software debounce
- `millis()`
- State tracking
- Non-blocking timing

## Implementations

- [C++ source](cpp/src/main.cpp) — Arduino framework with PlatformIO.
- Rust — planned; no implementation yet.

## Build and upload C++

Open this experiment's `cpp/` folder in VS Code. See the
[C++ setup guide](../docs/cpp-setup.md) for prerequisites and editor setup.

From the repository root:

```sh
pio run -d 05-button-debounce/cpp
pio run -d 05-button-debounce/cpp -t upload
```
