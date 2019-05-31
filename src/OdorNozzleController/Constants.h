// ----------------------------------------------------------------------------
// Constants.h
//
//
// Authors:
// Peter Polidoro peterpolidoro@gmail.com
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
enum{FUNCTION_COUNT_MAX=11};
enum{CALLBACK_COUNT_MAX=1};

extern ConstantString device_name;

extern ConstantString firmware_name;
extern const modular_server::FirmwareInfo firmware_info;

enum{CHANNEL_COUNT=1};
enum{CONTROLLER_COUNT=1};
extern const size_t nozzle_channel;

// Pins

// Units
extern ConstantString degrees_units;
extern ConstantString degrees_per_second_units;

// Properties
// Property values must be long, double, bool, long[], double[], bool[], char[], ConstantString *, (ConstantString *)[]
extern const long channel_count_min;
extern const long channel_count_max;
extern const long channel_count_default;

extern const long steps_per_position_units_min;
extern const long steps_per_position_units_max;
extern const long steps_per_position_units_default[CHANNEL_COUNT];

extern const long velocity_max_default[CHANNEL_COUNT];

extern const long velocity_min_default[CHANNEL_COUNT];

extern const long acceleration_max_default[CHANNEL_COUNT];

extern const ConstantString * const enable_polarity_default[CHANNEL_COUNT];

extern const bool step_polarity_inverted_default[CONTROLLER_COUNT];

extern const bool dir_polarity_inverted_default[CONTROLLER_COUNT];

extern const ConstantString * const switch_active_polarity_default[CONTROLLER_COUNT];

extern const long home_velocity_default[CHANNEL_COUNT];

extern const bool left_switch_stop_enabled_default[CHANNEL_COUNT];

extern const bool right_switches_enabled_default[CONTROLLER_COUNT];

extern const bool right_switch_stop_enabled_default[CHANNEL_COUNT];

// Parameters

// Functions
extern ConstantString enable_nozzle_function_name;
extern ConstantString disable_nozzle_function_name;
extern ConstantString nozzle_enabled_function_name;
extern ConstantString move_nozzle_by_function_name;
extern ConstantString move_nozzle_to_function_name;
extern ConstantString move_nozzle_at_function_name;
extern ConstantString stop_nozzle_function_name;
extern ConstantString get_nozzle_position_function_name;
extern ConstantString get_nozzle_velocity_function_name;
extern ConstantString nozzle_homing_function_name;
extern ConstantString nozzle_homed_function_name;

// Callbacks
extern ConstantString home_nozzle_callback_name;

// Errors
}
}
#include "5x3.h"
#include "3x2.h"
#endif
