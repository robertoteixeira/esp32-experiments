# 09 - Button Toggle

## Goal

Toggle an LED once per button press, keeping its state after release.

## Hardware and wiring

Use an ESP32 DevKit V1, breadboard, LED, 220 ohm resistor, push button,
and jumper wires.

```text
GPIO 23 -> 220 ohm resistor -> LED positive (long leg)
LED negative (short leg) -> GND
GPIO 22 -> push button -> GND
```

The button uses `INPUT_PULLUP`: released reads HIGH and pressed reads LOW.
No external pull-up resistor is needed.

## Behavior

The LED starts off. A button reading must stay stable for 50 milliseconds before
it is accepted. Each accepted press toggles the LED. Holding or releasing the
button does not toggle it again.

## Concepts learned

- Software debounce
- Detecting press events
- Preserving output state after an input is released

## Implementations

- [C++ source](cpp/src/main.cpp) — Arduino framework with PlatformIO.
- Rust — planned; no implementation yet.

## Build and upload C++

Open this experiment's `cpp/` folder in VS Code. See the
[C++ setup guide](../docs/cpp-setup.md) for prerequisites and editor setup.

From the repository root:

```sh
pio run -d 09-button-toggle/cpp
pio run -d 09-button-toggle/cpp -t upload
```
