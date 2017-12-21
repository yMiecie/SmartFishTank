/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    13/12/2017 21:34*/
/* P-Name:  SmartFishTank   */
/****************************/

#include "PHServices.h"
#include "DependenciesServices.h"

#define PIN_PHMETER  33

PHServices::PHServices(DependenciesServices* dependenciesServices) {
  m_$ = dependenciesServices;
  m_phmeter = new PHmeterBNC(PIN_PHMETER);
  m_currentPH = m_phmeter->pH();

  std::function<void (Timer *)> handler = [this](Timer *timer) {
      this->m_currentPH = this->m_phmeter->pH();
      Serial.printf("[PHServices::PHServices] Current pH %.2f.\n", this->m_currentPH);
  };

  m_dataTimer = new Timer(1000, handler, true);
  m_$->timerController()->add(m_dataTimer);
}

PHServices::~PHServices() {
  clearTimers();
  delete m_phmeter;
}

void PHServices::loop() {

}

float PHServices::getPH() {
  return m_currentPH;
}

void PHServices::clearTimers() {
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
