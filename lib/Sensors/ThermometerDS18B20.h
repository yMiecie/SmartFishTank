/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    07/09/2017 22:20*/
/* P-Name:  Sensors         */
/****************************/

#ifndef THERMOMETER_DS18B20_H
#define THERMOMETER_DS18B20_H

#include "Thermometer.h"

class OneWire;
class DallasTemperature;

class ThermometerDS18B20: public Thermometer
{

public:
  ThermometerDS18B20(uint8_t pin);
  virtual ~ThermometerDS18B20();
  virtual float temperature();
  float temperature(uint8_t device);

protected:
  uint8_t           m_pin;
  OneWire           *m_oneWire;
  DallasTemperature *m_sensors;
};

#endif
