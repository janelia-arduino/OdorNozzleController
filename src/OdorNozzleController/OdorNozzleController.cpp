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
  StageController::setup(constants::use_drivers);

  // Reset Watchdog
  resetWatchdog();

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

  // Functions

  // Callbacks
  modular_server::Callback & home_nozzle_callback = modular_server_.createCallback(constants::home_nozzle_callback_name);
  home_nozzle_callback.attachFunctor(makeFunctor((Functor1<modular_server::Pin *> *)0,*this,&OdorNozzleController::homeNozzleHandler));
  home_nozzle_callback.attachTo(modular_device_base::constants::bnc_a_pin_name,modular_server::constants::pin_mode_interrupt_falling);
  home_nozzle_callback.attachTo(modular_device_base::constants::btn_a_pin_name,modular_server::constants::pin_mode_interrupt_falling);
}

void OdorNozzleController::homeNozzle()
{
  homeStage();
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

void OdorNozzleController::homeNozzleHandler(modular_server::Pin * pin_ptr)
{
  homeNozzle();
}
