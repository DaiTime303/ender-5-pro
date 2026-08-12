/*
  Minimal Marlin Configuration_adv.h tailored choices for:
  - TMC2209 UART use
  - BLTouch behavior
  - Conservative defaults
*/

#ifndef CONFIGURATION_ADV_H
#define CONFIGURATION_ADV_H

//----------------------------- TMC2209 --------------------------------------
// Enable TMC UART (runtime configuration via UART)
#define TMC_USE_SW_UART // Some SKR Mini E3 V2 builds require software UART; Marlin will attempt hardware first

// StealthChop and CoolStep defaults
#define TMC2209_SGT 0

// Provide runtime current control via M906
#define TMC_MOTOR_CURRENT 1

//----------------------------- BLTouch -------------------------------------
#define BLTOUCH_DELAY 500 // (ms) Delay between deploy/stow and movement
#define BLTOUCH_FORCE_SW_MODE

//----------------------------- Filament Runout -------------------------------
// Leave commented; enable if you have a sensor
//#define FILAMENT_RUNOUT_SENSOR
//#define FILAMENT_RUNOUT_DISTANCE_MM 7

//----------------------------- Power Loss ----------------------------------
// Leave commented; enable if you have a supported PSU
//#define POWER_LOSS_RECOVERY

#endif // CONFIGURATION_ADV_H
