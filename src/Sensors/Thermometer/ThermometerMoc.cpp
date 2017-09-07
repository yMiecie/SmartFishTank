/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    07/09/2017 22:20*/
/* P-Name:  Smart Fish Tank */
/****************************/

#include "ThermometerMoc.h"

ThermometerMoc::ThermometerMoc()
{}

ThermometerMoc::~ThermometerMoc()
{}

float ThermometerMoc::temperature()
{
   m_currentTemperature = 19.0f;
   printf("[ThermometerMoc::temperature] Current temperature %.2f °C.", m_currentTemperature);

    return m_currentTemperature;
}
