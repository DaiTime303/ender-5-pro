/* Minimal, sanity-check-passing Configuration.h — adjust values for your hardware */
#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#define CONFIGURATION_H_VERSION 02010300
#define CONFIGURATION_H_AUTHOR "copilot@github - customized for DaiTime303"

#define ENDSTOPPULLUPS
#define Z_MIN_PROBE_ENDSTOP_HIT_STATE HIGH
#define MIN_STEPS_PER_SEGMENT 6
#define SERIAL_PORT 1

#define MOTHERBOARD BOARD_BTT_SKR_MINI_E3_V2_0
#define CUSTOM_MACHINE_NAME "Ender-5-Pro_MS"
#define BAUDRATE 115200

#define TEMP_SENSOR_0 1
#define TEMP_SENSOR_BED 1
#define HEATER_0_MAXTEMP 275
#define BED_MAXTEMP 120

/* Machine geometry - must exist and be consistent */
#define X_MIN_POS 0
#define Y_MIN_POS 0
#define Z_MIN_POS 0
#define X_BED_SIZE 220
#define Y_BED_SIZE 220
#define Z_MAX_POS 300

#define X_MAX_POS (X_MIN_POS + X_BED_SIZE)
#define Y_MAX_POS (Y_MIN_POS + Y_BED_SIZE)

/* Required sanity values */
#define HOMING_BUMP_DIVISOR { 2, 2, 1 }
#define BLOCK_BUFFER_SIZE 16
#define AXIS_RELATIVE_MODES { false, false, false }
#define HOMING_FEEDRATE_MM_M { 50*60, 50*60, 4*60 }

/* Arrays must match logical axes (3) for this Marlin branch */
#define DEFAULT_AXIS_STEPS_PER_UNIT   { 80, 80, 400 }  /* X, Y, Z */
#define DEFAULT_MAX_FEEDRATE          { 300, 300, 5 }  /* mm/s */
#define DEFAULT_MAX_ACCELERATION      { 1000, 1000, 100 }

/* Z probe / homing placeholders */
#define Z_PROBE_LOW_POINT -2

#ifndef HOMING_FEEDRATE_MM_M
#define HOMING_FEEDRATE_MM_M { (50*60), (50*60), (4*60) } /* mm/min X Y Z */

/* Probe / endstop options */
#define BLTOUCH
#define USE_PROBE_FOR_Z_HOMING
#define NOZZLE_TO_PROBE_OFFSET { 0.0, 0.0, -3.00 }
#define Z_SAFE_HOMING
#define AUTO_BED_LEVELING_BILINEAR
#define RESTORE_LEVELING_AFTER_G28
#define GRID_MAX_POINTS_X 5
#define GRID_MAX_POINTS_Y 5
#define Z_MIN_PROBE_REPEATABILITY_TEST

/* TMC placeholders */
#define X_DRIVER_TYPE  TMC2209
#define Y_DRIVER_TYPE  TMC2209
#define Z_DRIVER_TYPE  TMC2209
#define E0_DRIVER_TYPE TMC2209
#define HAVE_TMC2209 true

#define DEFAULT_AXIS_CURRENT 800
#define DEFAULT_E0_CURRENT 800

#define THERMAL_PROTECTION_HOTENDS
#define THERMAL_PROTECTION_BED
#define EEPROM_SETTINGS

#endif /* CONFIGURATION_H */
