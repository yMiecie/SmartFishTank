/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    27/09/2017 22:34*/
/* P-Name:  SmartFishTank   */
/****************************/

#include "DependenciesServices.h"

#define PIN_THERMOMETER  27

DependenciesServices::DependenciesServices() {
  m_timerController = new TimerController();
  m_thermometer = new ThermometerDS18B20(PIN_THERMOMETER);
}

DependenciesServices::~DependenciesServices() {
  delete m_timerController;
}

void DependenciesServices::loop() {

  	m_timerController->run();
}

/*
 *  Timer
 */
TimerController *DependenciesServices::timerController() {

  return m_timerController;
}
