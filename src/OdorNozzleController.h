// ----------------------------------------------------------------------------
// OdorNozzleController.h
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef ODOR_NOZZLE_CONTROLLER_H
#define ODOR_NOZZLE_CONTROLLER_H
#include <ArduinoJson.h>
#include <JsonStream.h>
#include <Array.h>
#include <Vector.h>
#include <ConstantVariable.h>
#include <Functor.h>

#include <ModularServer.h>
#include <ModularDeviceBase.h>
#include <StageController.h>

#include "OdorNozzleController/Constants.h"


class OdorNozzleController : public StageController
{
public:
  OdorNozzleController();
  virtual void setup();

private:
  modular_server::Property properties_[odor_nozzle_controller::constants::PROPERTY_COUNT_MAX];
  modular_server::Parameter parameters_[odor_nozzle_controller::constants::PARAMETER_COUNT_MAX];
  modular_server::Function functions_[odor_nozzle_controller::constants::FUNCTION_COUNT_MAX];
  modular_server::Callback callbacks_[odor_nozzle_controller::constants::CALLBACK_COUNT_MAX];

  // Handlers

};

#endif
