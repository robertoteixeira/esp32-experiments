# C++ setup

## Environment

The experiments use an ESP32 DevKit V1, the PlatformIO `esp32dev` board
configuration, and the Arduino framework. Install VS Code with PlatformIO IDE
and Microsoft C/C++ support. Connect the board using a data-capable USB cable.

## Open one experiment

Open the experiment's **cpp directory**, for example
`10-traffic-light/cpp`, as the VS Code folder. This is the PlatformIO project
root: it contains `platformio.ini`, `src/`, and local editor configuration.
The parent experiment directory contains the shared wiring documentation.

Use PlatformIO's Build and Upload actions. Upload replaces the program running
on the board; wire the matching circuit described in the experiment README.

## Command line

In a PlatformIO terminal, from the repository root:

```sh
pio run -d 10-traffic-light/cpp
pio run -d 10-traffic-light/cpp -t upload
```

Replace `10-traffic-light` with the experiment you want. Alternatively, open a
terminal inside its `cpp/` directory and run `pio run` or `pio run -t upload`.

For experiments that print serial messages (04 through 07):

```sh
pio device monitor -d 07-pir-timer/cpp -b 115200
```

## After the folder reorganization

Close the old experiment folder in VS Code and reopen its `cpp/` directory.
If completion still references old paths, run **PlatformIO: Rebuild C/C++
Project Index** from the Command Palette. Build output (`.pio/`) and generated
editor settings (`.vscode/`) remain ignored by Git. They are local artifacts,
not files that another checkout needs to copy.

If a moved build cache causes problems, run a clean build:

```sh
pio run -d 10-traffic-light/cpp -t clean
pio run -d 10-traffic-light/cpp
```
