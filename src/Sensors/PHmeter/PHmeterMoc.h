/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    07/09/2017 22:20*/
/* P-Name:  Smart Fish Tank */
/****************************/

#ifndef PHMETER_MOC_H
#define PHMETER_MOC_H

#include "PHmeter.h"

class PHmeterMoc: public PHmeter
{
    public:
    PHmeterMoc();
    virtual ~PHmeterMoc();
    virtual float pH();
};

#endif
