// ----------------------------------------------------------------------------
// OdorNozzleController.cpp
//
//
// Authors:
// Peter Polidoro peterpolidoro@gmail.com
// ----------------------------------------------------------------------------
#include "../OdorNozzleController.h"


using namespace odor_nozzle_controller;

OdorNozzleController::OdorNozzleController()
{
}

void OdorNozzleController::setup()
{
  // Parent Setup
  StepDirController::setup();

  // Reset Watchdog
  resetWatchdog();

  // Disable Chip Select Pins for Unused StepperController Drivers
  for (size_t channel=0; channel<stepper_controller::constants::CHANNEL_COUNT_MAX; ++channel)
  {
    size_t chip_select_pin = stepper_controller::constants::chip_select_pins[channel];
    pinMode(chip_select_pin,OUTPUT);
    digitalWrite(chip_select_pin,HIGH);
  }

  // Variable Setup

  // Set Device ID
  modular_server_.setDeviceName(constants::device_name);

  // Add Hardware

  // Pins

  // Add Firmware
  modular_server_.addFirmware(constants::firmware_info,
    properties_,
    parameters_,
    functions_,
    callbacks_);

  // Properties
  modular_server::Property & channel_count_property = modular_server_.property(step_dir_controller::constants::channel_count_property_name);
  channel_count_property.setDefaultValue(constants::channel_count_default);
  channel_count_property.setRange(constants::channel_count_min,constants::channel_count_max);

  modular_server::Property & steps_per_position_units_property = modular_server_.property(step_dir_controller::constants::steps_per_position_units_property_name);
  steps_per_position_units_property.setDefaultValue(constants::steps_per_position_units_default);
  steps_per_position_units_property.setRange(constants::steps_per_position_units_min,constants::steps_per_position_units_max);

  modular_server::Property & velocity_max_property = modular_server_.property(step_dir_controller::constants::velocity_max_property_name);
  velocity_max_property.setDefaultValue(constants::velocity_max_default);

  modular_server::Property & velocity_min_property = modular_server_.property(step_dir_controller::constants::velocity_min_property_name);
  velocity_min_property.setDefaultValue(constants::velocity_min_default);

  modular_server::Property & acceleration_max_property = modular_server_.property(step_dir_controller::constants::acceleration_max_property_name);
  acceleration_max_property.setDefaultValue(constants::acceleration_max_default);

  modular_server::Property & enable_polarity_property = modular_server_.property(step_dir_controller::constants::enable_polarity_property_name);
  enable_polarity_property.setDefaultValue(constants::enable_polarity_default);

  modular_server::Property & step_polarity_inverted_property = modular_server_.property(step_dir_controller::constants::step_polarity_inverted_property_name);
  step_polarity_inverted_property.setDefaultValue(constants::step_polarity_inverted_default);

  modular_server::Property & dir_polarity_inverted_property = modular_server_.property(step_dir_controller::constants::dir_polarity_inverted_property_name);
  dir_polarity_inverted_property.setDefaultValue(constants::dir_polarity_inverted_default);

  modular_server::Property & switch_active_polarity_property = modular_server_.property(step_dir_controller::constants::switch_active_polarity_property_name);
  switch_active_polarity_property.setDefaultValue(constants::switch_active_polarity_default);

  modular_server::Property & home_velocity_property = modular_server_.property(step_dir_controller::constants::home_velocity_property_name);
  home_velocity_property.setDefaultValue(constants::home_velocity_default);

  modular_server::Property & left_switch_stop_enabled_property = modular_server_.property(step_dir_controller::constants::left_switch_stop_enabled_property_name);
  left_switch_stop_enabled_property.setDefaultValue(constants::left_switch_stop_enabled_default);

  modular_server::Property & right_switches_enabled_property = modular_server_.property(step_dir_controller::constants::right_switches_enabled_property_name);
  right_switches_enabled_property.setDefaultValue(constants::right_switches_enabled_default);

  modular_server::Property & right_switch_stop_enabled_property = modular_server_.property(step_dir_controller::constants::right_switch_stop_enabled_property_name);
  right_switch_stop_enabled_property.setDefaultValue(constants::right_switch_stop_enabled_default);

  // Parameters
  modular_server::Parameter & position_parameter = modular_server_.parameter(step_dir_controller::constants::position_parameter_name);
  position_parameter.setUnits(constants::degrees_units);

  modular_server::Parameter & velocity_parameter = modular_server_.parameter(step_dir_controller::constants::velocity_parameter_name);
  velocity_parameter.setUnits(constants::degrees_per_second_units);

  // Functions
  modular_server::Function & enable_nozzle_function = modular_server_.createFunction(constants::enable_nozzle_function_name);
  enable_nozzle_function.attachFunctor(makeFunctor((Functor0 *)0,*this,&OdorNozzleController::enableNozzleHandler));

  modular_server::Function & disable_nozzle_function = modular_server_.createFunction(constants::disable_nozzle_function_name);
  disable_nozzle_function.attachFunctor(makeFunctor((Functor0 *)0,*this,&OdorNozzleController::disableNozzleHandler));

  modular_server::Function & nozzle_enabled_function = modular_server_.createFunction(constants::nozzle_enabled_function_name);
  nozzle_enabled_function.attachFunctor(makeFunctor((Functor0 *)0,*this,&OdorNozzleController::nozzleEnabledHandler));
  nozzle_enabled_function.setResultTypeBool();

  modular_server::Function & move_nozzle_by_function = modular_server_.createFunction(constants::move_nozzle_by_function_name);
  move_nozzle_by_function.attachFunctor(makeFunctor((Functor0 *)0,*this,&OdorNozzleController::moveNozzleByHandler));
  move_nozzle_by_function.addParameter(position_parameter);

  modular_server::Function & move_nozzle_to_function = modular_server_.createFunction(constants::move_nozzle_to_function_name);
  move_nozzle_to_function.attachFunctor(makeFunctor((Functor0 *)0,*this,&OdorNozzleController::moveNozzleToHandler));
  move_nozzle_to_function.addParameter(position_parameter);

  modular_server::Function & move_nozzle_at_function = modular_server_.createFunction(constants::move_nozzle_at_function_name);
  move_nozzle_at_function.attachFunctor(makeFunctor((Functor0 *)0,*this,&OdorNozzleController::moveNozzleAtHandler));
  move_nozzle_at_function.addParameter(velocity_parameter);

  modular_server::Function & stop_nozzle_function = modular_server_.createFunction(constants::stop_nozzle_function_name);
  stop_nozzle_function.attachFunctor(makeFunctor((Functor0 *)0,*this,&OdorNozzleController::stopNozzleHandler));

  modular_server::Function & get_nozzle_position_function = modular_server_.createFunction(constants::get_nozzle_position_function_name);
  get_nozzle_position_function.attachFunctor(makeFunctor((Functor0 *)0,*this,&OdorNozzleController::getNozzlePositionHandler));
  get_nozzle_position_function.setResultTypeLong();

  modular_server::Function & get_nozzle_velocity_function = modular_server_.createFunction(constants::get_nozzle_velocity_function_name);
  get_nozzle_velocity_function.attachFunctor(makeFunctor((Functor0 *)0,*this,&OdorNozzleController::getNozzleVelocityHandler));
  get_nozzle_velocity_function.setResultTypeLong();

  // Callbacks
  modular_server::Callback & home_nozzle_callback = modular_server_.createCallback(constants::home_nozzle_callback_name);
  home_nozzle_callback.attachFunctor(makeFunctor((Functor1<modular_server::Pin *> *)0,*this,&OdorNozzleController::homeNozzleHandler));
  home_nozzle_callback.attachTo(modular_device_base::constants::bnc_a_pin_name,modular_server::constants::pin_mode_interrupt_falling);
  home_nozzle_callback.attachTo(modular_device_base::constants::btn_a_pin_name,modular_server::constants::pin_mode_interrupt_falling);
}

void OdorNozzleController::enableNozzle()
{
  enable(constants::nozzle_channel);
}

void OdorNozzleController::disableNozzle()
{
  disable(constants::nozzle_channel);
}

bool OdorNozzleController::nozzleEnabled()
{
  return enabled() & (1 << constants::nozzle_channel);
}

void OdorNozzleController::moveNozzleBy(long position)
{
  moveBy(constants::nozzle_channel,position);
}

void OdorNozzleController::moveNozzleTo(long position)
{
  moveTo(constants::nozzle_channel,position);
}

void OdorNozzleController::moveNozzleAt(long velocity)
{
  moveAt(constants::nozzle_channel,velocity);
}

void OdorNozzleController::stopNozzle()
{
  stop(constants::nozzle_channel);
}

long OdorNozzleController::getNozzlePosition()
{
  return getPosition(constants::nozzle_channel);
}

long OdorNozzleController::getNozzleVelocity()
{
  return getVelocity(constants::nozzle_channel);
}

bool OdorNozzleController::homeNozzle()
{
  temporarilyEnableHomeSwitch(constants::nozzle_channel);
  return home(constants::nozzle_channel);
}

void OdorNozzleController::homedHandler(size_t channel)
{
  restoreHomeSwitch(constants::nozzle_channel);
}

// Handlers must be non-blocking (avoid 'delay')
//
// modular_server_.parameter(parameter_name).getValue(value) value type must be either:
// fixed-point number (int, long, etc.)
// floating-point number (float, double)
// bool
// const char *
// ArduinoJson::JsonArray *
// ArduinoJson::JsonObject *
// const ConstantString *
//
// For more info read about ArduinoJson parsing https://github.com/janelia-arduino/ArduinoJson
//
// modular_server_.property(property_name).getValue(value) value type must match the property default type
// modular_server_.property(property_name).setValue(value) value type must match the property default type
// modular_server_.property(property_name).getElementValue(element_index,value) value type must match the property array element default type
// modular_server_.property(property_name).setElementValue(element_index,value) value type must match the property array element default type

void OdorNozzleController::enableNozzleHandler()
{
  enableNozzle();
}

void OdorNozzleController::disableNozzleHandler()
{
  disableNozzle();
}

void OdorNozzleController::nozzleEnabledHandler()
{
  bool nozzle_enabled = nozzleEnabled();
  modular_server_.response().returnResult(nozzle_enabled);
}

void OdorNozzleController::moveNozzleByHandler()
{
  long position;
  modular_server_.parameter(step_dir_controller::constants::position_parameter_name).getValue(position);
  moveNozzleBy(position);
}

void OdorNozzleController::moveNozzleToHandler()
{
  long position;
  modular_server_.parameter(step_dir_controller::constants::position_parameter_name).getValue(position);
  moveNozzleTo(position);
}

void OdorNozzleController::moveNozzleAtHandler()
{
  long velocity;
  modular_server_.parameter(step_dir_controller::constants::velocity_parameter_name).getValue(velocity);
  moveNozzleAt(velocity);
}

void OdorNozzleController::stopNozzleHandler()
{
  stopNozzle();
}

void OdorNozzleController::getNozzlePositionHandler()
{
  long nozzle_position = getNozzlePosition();
  modular_server_.response().returnResult(nozzle_position);
}

void OdorNozzleController::getNozzleVelocityHandler()
{
  long nozzle_velocity = getNozzleVelocity();
  modular_server_.response().returnResult(nozzle_velocity);
}

void OdorNozzleController::homeNozzleHandler(modular_server::Pin * pin_ptr)
{
  homeNozzle();
}
