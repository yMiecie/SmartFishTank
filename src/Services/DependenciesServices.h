/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    27/09/2017 22:34*/
/* P-Name:  SmartFishTank   */
/****************************/

#ifndef DEPENDENCIESSERVICES_H
#define DEPENDENCIESSERVICES_H

#include <TimerController.h>
#include <Sensors.h>
#include "PHServices.h"
#include "TemperaturesServices.h"
#include "WaterLevelServices.h"
#include "images.h"
#include "fonts.h"

class DependenciesServices {

public:
  DependenciesServices();
  virtual ~DependenciesServices();

  void loop();

  // Timer
  TimerController       *timerController();
  PHServices            *phServices();
  TemperaturesServices  *temperaturesServices();
  WaterLevelServices    *waterLevelServices();


protected:
  TimerController       *m_timerController = NULL;
  PHServices            *m_phServices = NULL;
  TemperaturesServices  *m_temperaturesServices = NULL;
  WaterLevelServices    *m_waterLevelServices = NULL;
};

#endif
