// ----------------------------------------------------------------------------
// Constants.h
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef ODOR_NOZZLE_CONTROLLER_CONSTANTS_H
#define ODOR_NOZZLE_CONTROLLER_CONSTANTS_H
#include <ConstantVariable.h>
#include <StageController.h>


namespace odor_nozzle_controller
{
namespace constants
{
//MAX values must be >= 1, >= created/copied count, < RAM limit
enum{PROPERTY_COUNT_MAX=1};
enum{PARAMETER_COUNT_MAX=1};
enum{FUNCTION_COUNT_MAX=1};
enum{CALLBACK_COUNT_MAX=1};

extern ConstantString device_name;

extern ConstantString firmware_name;
extern const modular_server::FirmwareInfo firmware_info;

enum{CHANNEL_COUNT=1};
extern const long channel_count;

// Pins

// Units

// Properties
// Property values must be long, double, bool, long[], double[], bool[], char[], ConstantString *, (ConstantString *)[]
extern const long velocity_max_default[CHANNEL_COUNT];

extern const long velocity_min_default[CHANNEL_COUNT];

extern const long acceleration_max_default[CHANNEL_COUNT];

extern const long home_velocity_default[CHANNEL_COUNT];

extern const bool left_switch_stop_enabled_default[CHANNEL_COUNT];

extern const bool right_switches_enabled_default;

extern const bool right_switch_stop_enabled_default[CHANNEL_COUNT];

extern const bool invert_driver_direction_default[CHANNEL_COUNT];

extern const long run_current_default[CHANNEL_COUNT];

extern const long hold_current_default[CHANNEL_COUNT];

extern const long stage_position_min_default[CHANNEL_COUNT];

extern const long stage_position_max_default[CHANNEL_COUNT];

// Parameters

// Functions

// Callbacks
extern ConstantString home_nozzle_callback_name;

// Errors
}
}
#include "5x3.h"
#include "3x2.h"
#endif
