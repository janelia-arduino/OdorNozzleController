// ----------------------------------------------------------------------------
// OdorNozzleController.h
//
//
// Authors:
// Peter Polidoro peterpolidoro@gmail.com
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
#include <StepDirController.h>
#include <StepperController.h>

#include "OdorNozzleController/Constants.h"


class OdorNozzleController : public StepDirController
{
public:
  OdorNozzleController();
  virtual void setup();

  void enableNozzle();
  void disableNozzle();
  bool nozzleEnabled();

  void moveNozzleBy(long position);
  void moveNozzleTo(long position);
  void moveNozzleAt(long velocity);
  void stopNozzle();

  long getNozzlePosition();
  bool nozzleAtTargetPosition();
  long getNozzleVelocity();
  bool nozzleAtTargetVelocity();

  bool homeNozzle();
  bool nozzleHoming();
  bool nozzleHomed();

protected:
  // Handlers
  virtual void homedHandler(size_t channel);

private:
  modular_server::Property properties_[odor_nozzle_controller::constants::PROPERTY_COUNT_MAX];
  modular_server::Parameter parameters_[odor_nozzle_controller::constants::PARAMETER_COUNT_MAX];
  modular_server::Function functions_[odor_nozzle_controller::constants::FUNCTION_COUNT_MAX];
  modular_server::Callback callbacks_[odor_nozzle_controller::constants::CALLBACK_COUNT_MAX];

  // Handlers
  void enableNozzleHandler();
  void disableNozzleHandler();
  void nozzleEnabledHandler();
  void moveNozzleByHandler();
  void moveNozzleToHandler();
  void moveNozzleAtHandler();
  void stopNozzleHandler();
  void getNozzlePositionHandler();
  void nozzleAtTargetPositionHandler();
  void getNozzleVelocityHandler();
  void nozzleAtTargetVelocityHandler();
  void homeNozzleHandler(modular_server::Pin * pin_ptr);
  void nozzleHomingHandler();
  void nozzleHomedHandler();

};

#endif
