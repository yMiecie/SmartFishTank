/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    07/09/2017 22:20*/
/* P-Name:  Sensors         */
/****************************/

#ifndef PHMETER_H
#define PHMETER_H

#include <Arduino.h>

class PHmeter
{
    public:
    virtual float pH() = 0;

    protected:
    float m_currentPH;
};

#endif
