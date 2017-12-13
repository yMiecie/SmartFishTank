/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    07/09/2017 22:20*/
/* P-Name:  Sensors         */
/****************************/

#ifndef THERMOMETER_MOC_H
#define THERMOMETER_MOC_H

#include "Thermometer.h"

class ThermometerMoc: public Thermometer
{
    public:
    ThermometerMoc();
    virtual ~ThermometerMoc();
    virtual float temperature();
};

#endif
