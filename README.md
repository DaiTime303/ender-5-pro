# ender-5-pro
ender 5 pro with a microswiss direct drive extruder and microswiss all metal hot head kit with a big tree tech skr mini ev v2 cr touch
# Marlin configuration files for Ender 5 Pro + MicroSwiss direct drive + MicroSwiss all-metal hotend + CR Touch

This directory contains Configuration.h and Configuration_adv.h customized for:
- Printer: Creality Ender 5 Pro (220x220x300)
- Board: BigTreeTech SKR Mini E3 V2.0
- Drivers: TMC2209 (UART enabled)
- Extruder: MicroSwiss direct drive using stock Creality stepper
- Hotend/Bed thermistors: Creality stock (100k NTC)
- Probe: CR Touch (BLTouch-compatible) wired to the probe header

Files in this repo branch are automatically copied into the Marlin source and built by the GitHub Actions workflow when pushed to the branch `marlin-skr-mini-e3-v2-ender5pro`.

Important placeholder values you must verify after flashing:
- PROBE offsets: X_PROBE_OFFSET and Y_PROBE_OFFSET are left as placeholders (0.0/0.0). Measure and set them before first print or use M851 to set and M500 to save.
- Z_PROBE_OFFSET is set to -3.00 mm as you reported the CR Touch sits about 3mm higher than the nozzle. Fine-tune after flashing.
- TMC currents are conservative defaults; measure and tune for quieter operation.

Build instructions (local):
1. Checkout Marlin bugfix-2.1.x and copy these files to Marlin/Marlin/Configuration.h and Configuration_adv.h
2. Install PlatformIO and run: `platformio run -e STM32F103RC_btt`
3. The firmware binary will be at `.pio/build/STM32F103RC_btt/firmware.bin`

Flashing to SKR Mini E3 V2.0:
- Copy firmware.bin to the root of an SD card and insert into the board (power cycle to flash), or follow your preferred flashing method for SKR boards.

Post-flash checklist (run over USB terminal or OctoPrint):
1. Run `M503` to verify settings.
2. PID autotune for hotend (example): `M303 E0 S200` then save PID with `M500` after writing values with `M301`.
3. Calibrate E-steps: mark filament, extrude 100mm, measure and set with `M92 E<steps>` then `M500`.
4. Set probe offsets: measure X/Y/Z offsets and set with `M851 X<val> Y<val> Z<val>` and `M500`.
5. Run `G28` then `G29` to create a mesh bed leveling map. Verify first layer and adjust as needed.

If the Actions build fails, reply and I will inspect logs and iterate on the config and workflow.
