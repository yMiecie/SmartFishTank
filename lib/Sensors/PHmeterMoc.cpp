/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    07/09/2017 22:20*/
/* P-Name:  Sensors         */
/****************************/

#include "PHmeterMoc.h"

PHmeterMoc::PHmeterMoc()
{}

PHmeterMoc::~PHmeterMoc()
{}

float PHmeterMoc::pH()
{
   m_currentPH = 7.0f;
   printf("[PHmeterMoc::pH] Current pH %.2f .", m_currentPH);

    return m_currentPH;
}
