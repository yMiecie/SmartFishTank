/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    07/09/2017 23:00*/
/* P-Name:  Sensors         */
/****************************/

#include "PHmeterBNC.h"
//#include <pHProbe>

#define ADC_MAX 4095
//#define ADC_MAX 1023

PHmeterBNC::PHmeterBNC(uint8_t pin)
    :m_pin(pin)
{ }

PHmeterBNC::~PHmeterBNC()
{}

float PHmeterBNC::pH()
{

    int buf[10],temp;

    for(int i=0;i<10;i++)
    {
      buf[i]=analogRead(m_pin);
      delay(30);
    }

    for(int i=0;i<9;i++)
    {
      for(int j=i+1;j<10;j++)
      {
        if(buf[i]>buf[j])
        {
          temp=buf[i];
          buf[i]=buf[j];
          buf[j]=temp;
        }
      }
    }
    float avgValue=0.0f;
    for(int i=2;i<8;i++)
    avgValue+=buf[i];
    printf("[PHmeterBNC::pH] avgValue: %f", avgValue);
    avgValue = (float)avgValue / 6.0f;
    avgValue = ADC_MAX - avgValue;

    //This is the raw voltage value for the pH module
    //Calibration values:
    //1310@pH6.99
    //315@ph4.11
    float pHm = map(avgValue, 315, 1310, 411, 699); //maps voltage(Po) from calibration values at 4.00 and 7.00 pH
    m_pH = (pHm/100);

    // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
    float voltage = avgValue * (5.0 / (float)ADC_MAX);

    printf("[PHmeterBNC::pH] Current pH: %.2f - Voltage: %.2f - avgValue: %f\n", m_pH, voltage, avgValue);

    return m_pH;
}
