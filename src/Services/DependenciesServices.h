/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    27/09/2017 22:34*/
/* P-Name:  SmartFishTank   */
/****************************/

#ifndef DEPENDENCIESSERVICES_H
#define DEPENDENCIESSERVICES_H

#include <TimerController.h>
#include <Sensors.h>
#include "images.h"
#include "fonts.h"

// Thermometer
#define PIN_THERMOMETER  27

class DependenciesServices {

public:
  DependenciesServices();
  virtual ~DependenciesServices();

  void loop();

  // Timer
  TimerController *timerController();

  // Temperature.
  float getWaterTemperature();
  float getAirTemperature();

protected:
  TimerController     *m_timerController = NULL;
  Thermometer         *m_thermometer;
};

#endif
