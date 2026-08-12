The branch marlin-skr-mini-e3-v2-ender5pro contains two Marlin configuration files:

- Marlin/.github/marlin-config/Configuration.h
- Marlin/.github/marlin-config/Configuration_adv.h

These files configure Marlin for BigTreeTech SKR Mini E3 V2.0 (BOARD_BTT_SKR_MINI_E3_V2_0)
with conservative defaults for the Ender 5 Pro + MicroSwiss setup. Build with:

  platformio run -e STM32F103RC_btt

Important things to verify before powering the printer:
- Probe Z offset and X/Y offsets (CR Touch mounts vary)
- Stepper currents (X/Y/Z/E) — defaults are conservative placeholders
- TEMP_SENSOR_0 and TEMP_SENSOR_BED values

If you want changes, update the files on the feature branch and push.
