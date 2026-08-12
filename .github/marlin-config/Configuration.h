/*
  Minimal Marlin Configuration.h tailored for:
  - Ender 5 Pro
  - BTT SKR Mini E3 V2.0
  - TMC2209 UART drivers
  - CR Touch (BLTouch-compatible probe)

  NOTE: This file is a focused configuration that overrides the standard Marlin defaults
  for the settings we care about. Some distributions of Marlin require the full file; if
  the build fails due to missing options, we'll update with the full upstream Configuration.h.
*/

#ifndef CONFIGURATION_H
#define CONFIGURATION_H

//==============================================================================
//============================= Board and Printer ==============================
//==============================================================================
#define MOTHERBOARD BOARD_BTT_SKR_MINI_E3_V2_0

// Printer name
#define CUSTOM_MACHINE_NAME "Ender-5-Pro_MS"

// Baudrate
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
#define DEFAULT_AXIS_STEPS_PER_UNIT   { 80, 80, 400, 415 } // X, Y, Z, E (E is placeholder — calibrate E-steps)

#define DEFAULT_MAX_FEEDRATE          { 300, 300, 5, 25 }
#define DEFAULT_MAX_ACCELERATION      { 1000,1000,100,10000 }

//===========================================================================
//========================== Endstop / Probe Options =========================
//===========================================================================
// Use CR Touch as BLTouch-compatible probe
#define BLTOUCH
#define USE_PROBE_FOR_Z_HOMING

// Disable Z endstop - we use CR Touch
#define Z_MIN_PROBE_REPEATABILITY_TEST

// Probe offsets (placeholders)
// You reported the CR Touch sits about 3mm higher than the nozzle -> Z offset ~ -3.00
#define NOZZLE_TO_PROBE_OFFSET { 0.0, 0.0, -3.00 } // X, Y, Z offsets (set exact X/Y after measuring)

// Ensure safe homing
#define Z_SAFE_HOMING

// Enable Bilinear bed leveling for large beds
#define AUTO_BED_LEVELING_BILINEAR
#define RESTORE_LEVELING_AFTER_G28

//===========================================================================
//============================== TMC Drivers =================================
//===========================================================================
// Use TMC2209 drivers on SKR Mini E3 V2
#define X_DRIVER_TYPE  TMC2209
#define Y_DRIVER_TYPE  TMC2209
#define Z_DRIVER_TYPE  TMC2209
#define E0_DRIVER_TYPE TMC2209

// Use UART for runtime configuration
#define HAVE_TMC2209 true

// Software serial for Marlin to TMC communication (if needed) left default

// Default stepper current values (mA) - conservative starting values
#define DEFAULT_AXIS_CURRENT 800 // mA for X/Y
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

// Linear Advance / Input Shaper left disabled by default

#endif // CONFIGURATION_H
