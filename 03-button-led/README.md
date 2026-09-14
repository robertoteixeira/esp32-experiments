# 03 - Button-Controlled LED

## Goal

Use a push button as a digital input to control an external LED.

## Hardware used

- ESP32 DevKit V1
- Push button
- LED
- 220 ohm resistor
- Breadboard
- Jumper wires

## Pin connections

```text
GPIO 23 -> 220 ohm resistor -> LED positive leg
LED negative leg -> GND

GPIO 22 -> push button -> GND
```

GPIO 22 uses the ESP32's internal pull-up resistor, so no external pull-up
resistor is required.

## Behavior

The button reads HIGH when released and LOW when pressed. Pressing the button
turns the LED on, and releasing it turns the LED off.

## Concepts learned

- `INPUT_PULLUP`
- `digitalRead()`
- `digitalWrite()`
- `if` and `else`
- Digital input versus digital output

## Implementations

- [C++ source](cpp/src/main.cpp) — Arduino framework with PlatformIO.
- Rust — planned; no implementation yet.

## Build and upload C++

Open this experiment's `cpp/` folder in VS Code. See the
[C++ setup guide](../docs/cpp-setup.md) for prerequisites and editor setup.

From the repository root:

```sh
pio run -d 03-button-led/cpp
pio run -d 03-button-led/cpp -t upload
```
