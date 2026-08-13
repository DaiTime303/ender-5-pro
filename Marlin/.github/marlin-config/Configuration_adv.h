/*
  Marlin Configuration_adv.h - additions for SKR Mini E3 V2.0 / Ender 5 Pro
  This file contains advanced settings: stepper currents, TMC defaults, probe delays
  and a few safety tweaks. Review and tune currents and probe offsets before first
  power-up. Commit is placed on branch: marlin-skr-mini-e3-v2-ender5pro
*/

#ifndef CONFIGURATION_ADV_H
#define CONFIGURATION_ADV_H

// Command queue settings
#define BUFSIZE 4              // Number of commands in the queue (4-16)
#define MAX_CMD_SIZE 96        // Maximum length of a single command line

// -------------------------- Stepper motor currents --------------------------
// Values are in mA. Start conservative and tune up as needed.
#ifndef X_CURRENT
  #define X_CURRENT 800
#endif
#ifndef Y_CURRENT
  #define Y_CURRENT 800
#endif
#ifndef Z_CURRENT
  #define Z_CURRENT 800
#endif
#ifndef E0_CURRENT
  #define E0_CURRENT 800
#endif

// -------------------------- TMC driver settings ----------------------------
// On SKR Mini E3 V2.0 using TMC2209 via UART. If you prefer SW UART set
// TMC_USE_SW_UART in this file or in Configuration.h/board definitions.

// Enable TMC debugging if you need to view registers (comment out for normal use)
//#define TMC_DEBUG

// StealthChop (quiet) is usually okay for X/Y; move to SpreadCycle for heavy loads.
#define STEALTHCHOP_XY

// TMC2209 Chopper Timing Configuration
#define CHOPPER_TIMING { \
  .toff = 3,           /* Off time (clock cycles) */ \
  .hstrt = 1,          /* Hysteresis start */ \
  .hend = 2            /* Hysteresis end */ \
}

// StallGuard/Load detection is not typically used on these printers but can be
// enabled later if you add sensors.

// -------------------------- BLTouch / Probe tweaks -------------------------
// Allow a short delay after deploying probe before probing
#define BLTOUCH_DELAY 200

// Retract before homing Z (helps CR Touch on some mounts)
#define Z_CLEARANCE_DEPLOY_PROBE 5
#define Z_CLEARANCE_BETWEEN_PROBES 2
#define Z_AFTER_PROBE 5

// -------------------------- Safety / Thermal -------------------------------
// Increase the allowed watch period for long bed meshes or slow probes
#define TEMP_RESIDENCY_TIME 10
#define TEMP_RESIDENCY_HYSTERESIS 3

// -------------------------- Misc Helpers ----------------------------------
// Faster LCD backlight turnoff when idle to avoid heat contribution
//#define LCD_BACKLIGHT_TIMEOUT 60

// -------------------------- Notes & Next Steps -----------------------------
// - Verify X_CURRENT/Y_CURRENT/Z_CURRENT/E0_CURRENT against real driver/stepper
//   ratings. Typical values for SKR Mini E3 with TMC2209 and Ender steppers
//   are 600-900 mA depending on hardware and microstepping.
// - If you want HW-UART for TMC2209, ensure the board definition sets
//   the correct UART pins or configure Software UART here.
// - Tune BLTOUCH probe Z offset precisely and update Configuration.h
// - After merging to your base branch, run PlatformIO build:
//     platformio run -e STM32F103RC_btt

#endif // CONFIGURATION_ADV_H
