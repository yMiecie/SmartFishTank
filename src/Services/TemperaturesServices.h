/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    13/12/2017 21:34*/
/* P-Name:  SmartFishTank   */
/****************************/

#ifndef TEMPERATURESSERVICES_H
#define TEMPERATURESSERVICES_H

#include <Sensors.h>

class Timer;
class DependenciesServices;

class TemperaturesServices {

public:
  TemperaturesServices(DependenciesServices* dependenciesServices);
  virtual ~TemperaturesServices();

  void loop();

  float getWaterTemperature();
  float getAirTemperature();

protected:
  void clearTimers();

  DependenciesServices  *m_$ = NULL;
  ThermometerDS18B20    *m_thermometer = NULL;
  Timer                 *m_dataTimer = NULL;
  Timer                 *m_comTimer = NULL;
  float                 m_currentWaterTemperature;
  float                 m_currentAirTemperature;
};

#endif
