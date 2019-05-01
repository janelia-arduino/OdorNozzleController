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
  .version_minor=0,
  .version_patch=0,
};

const bool use_drivers = false;

// Pins

// Units

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
  -250,
};

const bool left_switch_stop_enabled_default[CHANNEL_COUNT] =
{
  true,
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

// Callbacks
CONSTANT_STRING(home_nozzle_callback_name,"homeNozzle");

// Errors
}
}
