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
  .version_major=1,
  .version_minor=0,
  .version_patch=0,
};

const long channel_count = CHANNEL_COUNT;

// Pins

// Units

// Properties
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

const long home_velocity_default[CHANNEL_COUNT] =
{
  -250,
};

const bool invert_driver_direction_default[CHANNEL_COUNT] =
{
  false,
};

const long run_current_default[CHANNEL_COUNT] =
{
  20,
};

const long hold_current_default[CHANNEL_COUNT] =
{
  10,
};

const bool left_switch_stop_enabled_default[CHANNEL_COUNT] =
{
  true,
};

const bool right_switches_enabled_default = false;

const bool right_switch_stop_enabled_default[CHANNEL_COUNT] =
{
  false,
};

const long stage_position_min_default[CHANNEL_COUNT] =
{
  0,
};

const long stage_position_max_default[CHANNEL_COUNT] =
{
  10000,
};

// Parameters

// Functions

// Callbacks
CONSTANT_STRING(home_nozzle_callback_name,"homeNozzle");

// Errors
}
}
