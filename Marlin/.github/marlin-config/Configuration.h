/*
  Marlin Configuration.h - adapted from Marlin bugfix-2.1.x
  Customized for: Ender 5 Pro + MicroSwiss direct drive + MicroSwiss all-metal hotend + CR Touch
  Board: BTT SKR Mini E3 V2.0 (STM32F103RC_btt)

  Note: This file includes the required CONFIGURATION_H_VERSION and compatibility
  defines so it satisfies Marlin's SanityCheck when building against the
  bugfix-2.1.x tree.
*/

#ifndef CONFIGURATION_H
#define CONFIGURATION_H

// Configuration header version to satisfy Marlin's sanity checks
#define CONFIGURATION_H_VERSION 02010300
#define CONFIGURATION_H_AUTHOR "copilot@github - customized for DaiTime303"

// Minimum steps per segment - satisfy the Changes.h requirement
#define MIN_STEPS_PER_SEGMENT 6

// Serial port (must be 1..9 or -1 for Native USB)
#define SERIAL_PORT 1

//==============================================================================
//============================= Board and Printer ==============================
//==============================================================================
#define MOTHERBOARD BOARD_BTT_SKR_MINI_E3_V2_0

// Printer name
#define CUSTOM_MACHINE_NAME "Ender-5-Pro_MS"

// Communication speed
#define BAUDRATE 115200

//===========================================================================
//============================ Thermal Settings ==============================
//===========================================================================

// Thermistors
#define TEMP_SENSOR_0 1   // Hotend - Creality stock 100k
#define TEMP_SENSOR_BED 1 // Bed - Creality stock 100k

// Safety limits
#define HEATER_0_MAXTEMP 275
#define BED_MAXTEMP 120

//===========================================================================
//============================= Machine Settings =============================
//===========================================================================

// Travel limits (mm) after homing
#define X_BED_SIZE 220
#define Y_BED_SIZE 220
#define Z_MAX_POS 300

#define X_MIN_POS 0
#define Y_MIN_POS 0
#define Z_MIN_POS 0

// Default axis steps per unit
#define DEFAULT_AXIS_STEPS_PER_UNIT   { 80, 80, 400, 415 } // X, Y, Z, E (E is placeholder — calibrate)

#define DEFAULT_MAX_FEEDRATE          { 300, 300, 5, 25 }
#define DEFAULT_MAX_ACCELERATION      { 1000,1000,100,10000 }

#define X_MAX_POS 220
#define Y_MAX_POS 220

// Homing settings
#define HOMING_BUMP_DIVISOR { 8, 8, 4 }

// Block buffer size for movement commands
#define BLOCK_BUFFER_SIZE 16

// Axis relative modes (X, Y, Z)
#define AXIS_RELATIVE_MODES { false, false, false }

// Maximum position for X and Y axes
#define X_MAX_POS 220
#define Y_MAX_POS 220
//===========================================================================
//========================== Endstop / Probe Options =========================
//===========================================================================
// Use CR Touch as BLTouch-compatible probe
#define BLTOUCH
#define USE_PROBE_FOR_Z_HOMING

// Probe offsets (placeholders)
// You reported the CR Touch sits about 3mm higher than the nozzle -> Z offset ~ -3.00
#define NOZZLE_TO_PROBE_OFFSET { 0.0, 0.0, -3.00 } // X, Y, Z offsets (set exact X/Y after measuring)

// Ensure safe homing
#define Z_SAFE_HOMING

// Enable Bilinear bed leveling for large beds
#define AUTO_BED_LEVELING_BILINEAR
#define RESTORE_LEVELING_AFTER_G28

// Use probe for homing (disable mechanical Z endstop)
#define Z_MIN_PROBE_REPEATABILITY_TEST

//===========================================================================
//============================== TMC Drivers =================================
//===========================================================================
// Use TMC2209 drivers on SKR Mini E3 V2
#define X_DRIVER_TYPE  TMC2209
#define Y_DRIVER_TYPE  TMC2209
#define Z_DRIVER_TYPE  TMC2209
#define E0_DRIVER_TYPE TMC2209

// Enable HW UART if supported; fallback to SW UART set in Configuration_adv
#define HAVE_TMC2209 true

// Default stepper current values (mA) - conservative starting values
// These are placeholders; tune using M906 or via configuration
#define DEFAULT_AXIS_CURRENT 800 // mA for X/Y/Z (set driver-specific in Configuration_adv or via M906)
#define DEFAULT_E0_CURRENT 800

//===========================================================================
//============================ Safety & Misc =================================
//===========================================================================
#define THERMAL_PROTECTION_HOTENDS
#define THERMAL_PROTECTION_BED

// Enable EEPROM so settings can be tuned and saved without reflashing
#define EEPROM_SETTINGS

//===========================================================================
//=============================== Extra Features =============================
//===========================================================================
// Keep Linear Advance and Input Shaper disabled by default; enable later if desired

#endif // CONFIGURATION_H
