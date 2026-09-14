# 04 - Button Serial Monitoring

## Goal

Monitor a push button through the PlatformIO Serial Monitor while using it to
control an external LED.

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

The button reads HIGH when released and LOW when pressed. Pressing the button
turns the LED on, and releasing it turns the LED off.

The Serial Monitor runs at 115200 baud. The experiment initially printed the
raw button values (`1` when released and `0` when pressed), then changed to the
more readable messages `Button released` and `Button pressed`.

## Concepts learned

- `Serial.begin()`
- `Serial.println()`
- Baud rate
- PlatformIO Serial Monitor
- Serial debugging

## Implementations

- [C++ source](cpp/src/main.cpp) — Arduino framework with PlatformIO.
- Rust — planned; no implementation yet.

## Build and upload C++

Open this experiment's `cpp/` folder in VS Code. See the
[C++ setup guide](../docs/cpp-setup.md) for prerequisites and editor setup.

From the repository root:

```sh
pio run -d 04-button-serial/cpp
pio run -d 04-button-serial/cpp -t upload
```
