/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    07/09/2017 22:20*/
/* P-Name:  Sensors         */
/****************************/

#ifndef PHMETER_BNC_H
#define PHMETER_BNC_H

#include "PHmeter.h"

class PHmeterBNC: public PHmeter
{

public:
  PHmeterBNC(uint8_t pin);
  virtual ~PHmeterBNC();
  virtual float pH();

protected:
  uint8_t m_pin;
  float   m_po = 0;
  float   m_pH = 10;

};

#endif
