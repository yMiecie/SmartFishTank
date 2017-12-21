/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    13/12/2017 21:34*/
/* P-Name:  SmartFishTank   */
/****************************/

#include "TemperaturesServices.h"
#include "DependenciesServices.h"

#define PIN_THERMOMETER  27

TemperaturesServices::TemperaturesServices(DependenciesServices* dependenciesServices)
: m_$(dependenciesServices) {

  m_thermometer = new ThermometerDS18B20(PIN_THERMOMETER);
  m_currentAirTemperature = m_thermometer->temperature(0);
  m_currentWaterTemperature = m_thermometer->temperature(1);

  std::function<void (Timer *)> handler = [this](Timer *timer) {
    this->m_currentAirTemperature = this->m_thermometer->temperature(0);
    this->m_currentWaterTemperature = this->m_thermometer->temperature(1);
      Serial.printf("[ThermometerDS18B20::temperature] Current temperature in air %.2f °C.\n", m_currentAirTemperature);
      Serial.printf("[ThermometerDS18B20::temperature] Current temperature in water %.2f °C.\n", m_currentWaterTemperature);
  };

  m_dataTimer = new Timer(3000, handler, true);
  m_$->timerController()->add(m_dataTimer);
}

TemperaturesServices::~TemperaturesServices() {
  clearTimers();
  delete m_thermometer;
}

void TemperaturesServices::loop() {
}

float TemperaturesServices::getWaterTemperature() {
  return m_currentWaterTemperature;
}

float TemperaturesServices::getAirTemperature() {
  return m_currentAirTemperature;
}

void TemperaturesServices::clearTimers() {
    if (m_dataTimer != NULL) {
        m_$->timerController()->remove(m_dataTimer->id);
        delete m_dataTimer;
        m_dataTimer = NULL;
    }

    if (m_comTimer != NULL) {
        m_$->timerController()->remove(m_comTimer->id);
        delete m_comTimer;
        m_comTimer = NULL;
    }
}
