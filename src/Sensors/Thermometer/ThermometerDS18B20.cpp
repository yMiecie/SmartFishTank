/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    07/09/2017 23:00*/
/* P-Name:  Smart Fish Tank */
/****************************/

#include "ThermometerDS18B20.h"

ThermometerDS18B20::ThermometerDS18B20(uint8_t pin)
    :m_pin(pin)
{}

ThermometerDS18B20::~ThermometerDS18B20()
{}

float ThermometerDS18B20::temperature()
{
  m_currentTemperature = 19.0f;
  printf("[ThermometerDS18B20::temperature] Current temperature %.2f °C.", m_currentTemperature);

    return m_currentTemperature;
}
