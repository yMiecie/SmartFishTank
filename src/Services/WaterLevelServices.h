/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    13/12/2017 21:34*/
/* P-Name:  SmartFishTank   */
/****************************/

#ifndef WATERLEVELSERVICES_H
#define WATERLEVELSERVICES_H

#include <Sensors.h>

class DependenciesServices;

class WaterLevelServices {

public:
  WaterLevelServices(DependenciesServices* dependenciesServices);
  virtual ~WaterLevelServices();

  void loop();

  bool isWaterLevelOK();

protected:
  DependenciesServices  *m_$;
  Button                *m_waterLevelSensor;
};

#endif
