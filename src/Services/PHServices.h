/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    13/12/2017 21:34*/
/* P-Name:  SmartFishTank   */
/****************************/

#ifndef PHSERVICES_H
#define PHSERVICES_H

#include <Sensors.h>

class Timer;
class DependenciesServices;

class PHServices {

public:
  PHServices(DependenciesServices* dependenciesServices);
  virtual ~PHServices();

  void loop();

  float getPH();

protected:
  void clearTimers();

  DependenciesServices  *m_$;
  PHmeter               *m_phmeter;
  Timer                 *m_dataTimer = NULL;
  Timer                 *m_comTimer = NULL;
  float                 m_currentPH;
};

#endif
