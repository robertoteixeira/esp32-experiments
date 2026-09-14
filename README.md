# ESP32 Experiments

A collection of small ESP32 experiments for learning embedded development.
C++ implementations use PlatformIO and the Arduino framework. Rust versions
are planned alongside them, using the same wiring and expected behavior.

## Repository structure

Each experiment owns its circuit documentation and independent language projects:

```text
01-led-on/
├── README.md          # Shared wiring, behavior, and learning notes
└── cpp/               # Independent PlatformIO project
    ├── platformio.ini
    └── src/main.cpp
docs/
└── cpp-setup.md
```

Future Rust implementations will live in each experiment's `rust/` directory.
No Rust projects or toolchain configuration have been added yet.

## Getting started

1. Choose an experiment below and read its wiring instructions.
2. Open that experiment's **cpp/** folder in VS Code with PlatformIO.
3. Build and upload using the [C++ setup guide](docs/cpp-setup.md).

Each upload runs one experiment on the board. Disconnect USB before changing
wiring, and use a separate 220 ohm resistor for each LED.

## Experiments

| Experiment | C++ | Rust |
|---|---|---|
| [01-led-on — LED on](01-led-on/README.md) | [Available](01-led-on/cpp/src/main.cpp) | Planned |
| [02-led-blink — LED blink](02-led-blink/README.md) | [Available](02-led-blink/cpp/src/main.cpp) | Planned |
| [03-button-led — Button-controlled LED](03-button-led/README.md) | [Available](03-button-led/cpp/src/main.cpp) | Planned |
| [04-button-serial — Button serial monitoring](04-button-serial/README.md) | [Available](04-button-serial/cpp/src/main.cpp) | Planned |
| [05-button-debounce — Button debounce](05-button-debounce/README.md) | [Available](05-button-debounce/cpp/src/main.cpp) | Planned |
| [06-pir-led — PIR motion-controlled LED](06-pir-led/README.md) | [Available](06-pir-led/cpp/src/main.cpp) | Planned |
| [07-pir-timer — PIR motion timer](07-pir-timer/README.md) | [Available](07-pir-timer/cpp/src/main.cpp) | Planned |
| [08-non-blocking-blink — Non-blocking LED blink](08-non-blocking-blink/README.md) | [Available](08-non-blocking-blink/cpp/src/main.cpp) | Planned |
| [09-button-toggle — Button toggle](09-button-toggle/README.md) | [Available](09-button-toggle/cpp/src/main.cpp) | Planned |
| [10-traffic-light — Traffic light with pedestrian button](10-traffic-light/README.md) | [Available](10-traffic-light/cpp/src/main.cpp) | Planned |

## Hardware used so far

- ESP32 DevKit V1 (`esp32dev`)
- Breadboard and jumper wires
- LEDs and 220 ohm resistors
- Push buttons
- HC-SR501 PIR motion sensor
- USB data cable
- Multimeter for circuit checks

## Learning workflow

Experiments build progressively on earlier concepts. Keep implementations
self-contained so the complete behavior is visible in each example. Shared
experiment READMEs describe the hardware; language-specific setup belongs in
`docs/`. Completed experiments are recorded with Git commits.
