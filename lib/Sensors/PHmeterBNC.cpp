/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    07/09/2017 23:00*/
/* P-Name:  Sensors         */
/****************************/

#include "PHmeterBNC.h"

PHmeterBNC::PHmeterBNC(uint8_t pin)
    :m_pin(pin)
{}

PHmeterBNC::~PHmeterBNC()
{}

float PHmeterBNC::pH()
{
  m_currentPH = 7.0f;
  printf("[PHmeterBNC::pH] Current pH %.2f .", m_currentPH);

    return m_currentPH;
}
