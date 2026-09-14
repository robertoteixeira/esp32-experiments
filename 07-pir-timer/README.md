# 07 - PIR Motion Timer

## Goal

Keep an LED on for five seconds after the last motion detected by an HC-SR501
PIR sensor without blocking the program.

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

Detected motion turns the LED on and prints `Motion detected - LED ON`. The LED
stays on until five seconds have passed since the last detected motion. Any new
motion restarts the five-second timer.

When the timer expires, the LED turns off and the Serial Monitor prints
`LED OFF after 5 seconds`.

## Concepts learned

- Event-driven behavior
- Non-blocking timers
- `millis()`
- State tracking
- Resetting timers
- Sensor-driven output

## Implementations

- [C++ source](cpp/src/main.cpp) — Arduino framework with PlatformIO.
- Rust — planned; no implementation yet.

## Build and upload C++

Open this experiment's `cpp/` folder in VS Code. See the
[C++ setup guide](../docs/cpp-setup.md) for prerequisites and editor setup.

From the repository root:

```sh
pio run -d 07-pir-timer/cpp
pio run -d 07-pir-timer/cpp -t upload
```
