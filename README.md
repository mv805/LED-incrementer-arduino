# LED Incrementer Arduino Assembly

This project is the firmware and design documentation for the LED Incrementer Arduino mechatronic assembly, part number `10029482-3`.

The assembly controls a blinking LED. Pressing the increment button makes the LED blink faster by reducing the flash interval. When the minimum interval is reached, the next button press wraps the interval back to the maximum. The current interval is shown on the Arduino Uno R4 WiFi LED matrix, and a status LED indicates when the button is pressed.

## Project Contents

- `firmware/` - PlatformIO firmware project for the Arduino Uno R4 WiFi
- `hardware/` - KiCad schematic and PCB design files
- `docs/configuration.md` - Master assembly configuration
- `docs/requirements.md` - Numbered functional requirements
- `docs/hardware-interface.md` - Hardware signals and interface behavior
- `docs/BOM.md` - Bill of materials
- `docs/test-plan.md` - Requirements-traced test plan

## Current Configuration

- Hardware: Rev A
- Firmware: `v0.1.0`
- Release state: Released

The firmware is built with PlatformIO using the Arduino framework and the Arduino Graphics library.
