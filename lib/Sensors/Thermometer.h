/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    07/09/2017 22:20*/
/* P-Name:  Sensors         */
/****************************/

#ifndef THERMOMETER_H
#define THERMOMETER_H

#include <Arduino.h>

class Thermometer
{
    public:
    virtual float temperature() = 0;

    protected:
    float m_currentTemperature;
};

#endif
