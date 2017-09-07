/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    07/09/2017 22:38*/
/* P-Name:  Smart Fish Tank */
/****************************/

#ifndef DISPLAY_SSD1306_H
#define DISPLAY_SSD1306_H

#include "Display.h"
#include "SSD1306.h"

class DisplaySSD1306: public Display
{
public:
  DisplaySSD1306(uint8_t sda, uint8_t scl);
  virtual ~DisplaySSD1306();

  // Image functions
  virtual void drawXbm(int16_t x, int16_t y, int16_t width, int16_t height, const char *xbm);

  // Text functions
  virtual void drawString(int16_t x, int16_t y, String text);
  virtual uint16_t getStringWidth(String text);
  virtual void setTextAlignment(DISPLAY_TEXT_ALIGNMENT textAlignment);
  virtual void setFont(const char *fontData);

  // Display functions
  virtual void displayOn(void);
  virtual void displayOff(void);
  virtual void display(void);
  virtual void clear(void);

private:
  SSD1306 m_display;
  uint8_t m_sda;
  uint8_t m_scl;
};

#endif
