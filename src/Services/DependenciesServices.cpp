/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    27/09/2017 22:34*/
/* P-Name:  SmartFishTank   */
/****************************/

#include "DependenciesServices.h"

#define PIN_THERMOMETER  27

DependenciesServices::DependenciesServices() {
  m_timerController = new TimerController();
  m_phServices = new PHServices(this);
  m_temperaturesServices = new TemperaturesServices(this);
  m_waterLevelServices = new WaterLevelServices(this);
}

DependenciesServices::~DependenciesServices() {
  delete m_timerController;
  delete m_phServices;
  delete m_temperaturesServices;
  delete m_waterLevelServices;
}

void DependenciesServices::loop() {
  	m_timerController->run();
    m_temperaturesServices->loop();
    m_phServices->loop();
    m_waterLevelServices->loop();
}

/*
 *  Getters
 */
TimerController *DependenciesServices::timerController() { return m_timerController; }

PHServices *DependenciesServices::phServices() { return m_phServices; }

TemperaturesServices *DependenciesServices::temperaturesServices() { return m_temperaturesServices; }

WaterLevelServices *DependenciesServices::waterLevelServices() { return m_waterLevelServices; }
