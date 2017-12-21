/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    13/12/2017 21:34*/
/* P-Name:  SmartFishTank   */
/****************************/

#include "WaterLevelServices.h"
#include "DependenciesServices.h"

#define PIN_WATER_SENSOR  27

WaterLevelServices::WaterLevelServices(DependenciesServices* dependenciesServices) {
  m_$ = dependenciesServices;
  m_waterLevelSensor = new Button(PIN_WATER_SENSOR, BUTTON_TYPE::BUTTON_TYPE_ACTIVE_LOW);
}

WaterLevelServices::~WaterLevelServices() {
  delete m_waterLevelSensor;
}

void WaterLevelServices::loop() {

}

bool WaterLevelServices::isWaterLevelOK() {
  return true;
}
