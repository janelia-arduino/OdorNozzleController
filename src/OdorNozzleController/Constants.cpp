// ----------------------------------------------------------------------------
// Constants.cpp
//
//
// Authors:
// Peter Polidoro peterpolidoro@gmail.com
// ----------------------------------------------------------------------------
#include "Constants.h"


namespace odor_nozzle_controller
{
namespace constants
{
CONSTANT_STRING(device_name,"odor_nozzle_controller");

CONSTANT_STRING(firmware_name,"OdorNozzleController");
// Use semantic versioning http://semver.org/
const modular_server::FirmwareInfo firmware_info =
{
  .name_ptr=&firmware_name,
  .version_major=2,
  .version_minor=1,
  .version_patch=0,
};

const size_t nozzle_channel = 0;

// Pins

// Units
CONSTANT_STRING(degrees_units,"degrees");
CONSTANT_STRING(degrees_per_second_units,"degrees/s");

// Properties
const long channel_count_min = CHANNEL_COUNT;
const long channel_count_max = CHANNEL_COUNT;
const long channel_count_default = CHANNEL_COUNT;

const long steps_per_position_units_min = 142;
const long steps_per_position_units_max = 142;
const long steps_per_position_units_default[CHANNEL_COUNT] =
{
  142,
};

const long velocity_max_default[CHANNEL_COUNT] =
{
  1000,
};

const long velocity_min_default[CHANNEL_COUNT] =
{
  100,
};

const long acceleration_max_default[CHANNEL_COUNT] =
{
  1000,
};

const ConstantString * const enable_polarity_default[CHANNEL_COUNT] =
{
  &step_dir_controller::constants::polarity_high,
};

const bool step_polarity_inverted_default[CONTROLLER_COUNT] =
{
  true,
};

const bool dir_polarity_inverted_default[CONTROLLER_COUNT] =
{
  true,
};

const ConstantString * const switch_active_polarity_default[CONTROLLER_COUNT] =
{
  &step_dir_controller::constants::polarity_high,
};

const long home_velocity_default[CHANNEL_COUNT] =
{
  -36,
};

const bool left_switch_stop_enabled_default[CHANNEL_COUNT] =
{
  false,
};

const bool right_switches_enabled_default[CONTROLLER_COUNT] =
{
  false,
};

const bool right_switch_stop_enabled_default[CHANNEL_COUNT] =
{
  false,
};

// Parameters

// Functions
CONSTANT_STRING(enable_nozzle_function_name,"enableNozzle");
CONSTANT_STRING(disable_nozzle_function_name,"disableNozzle");
CONSTANT_STRING(nozzle_enabled_function_name,"nozzleEnabled");
CONSTANT_STRING(move_nozzle_by_function_name,"moveNozzleBy");
CONSTANT_STRING(move_nozzle_to_function_name,"moveNozzleTo");
CONSTANT_STRING(move_nozzle_at_function_name,"moveNozzleAt");
CONSTANT_STRING(stop_nozzle_function_name,"stopNozzle");
CONSTANT_STRING(get_nozzle_position_function_name,"getNozzlePosition");
CONSTANT_STRING(get_nozzle_velocity_function_name,"getNozzleVelocity");
CONSTANT_STRING(nozzle_homing_function_name,"nozzleHoming");
CONSTANT_STRING(nozzle_homed_function_name,"nozzleHomed");

// Callbacks
CONSTANT_STRING(home_nozzle_callback_name,"homeNozzle");

// Errors
}
}
