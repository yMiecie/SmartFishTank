/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    07/09/2017 22:38*/
/* P-Name:  Display         */
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

  // Size
  virtual int width();
  virtual int height();
  /*********************/
  /* Draw functions */
  /*********************/
  // Draw a pixel at given position
  virtual void setPixel(int16_t x, int16_t y);
  virtual void drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1);
  virtual void drawRect(int16_t x, int16_t y, int16_t width, int16_t height);
  virtual void fillRect(int16_t x, int16_t y, int16_t width, int16_t height);
  virtual void drawCircle(int16_t x, int16_t y, int16_t radius);
  virtual void drawCircleQuads(int16_t x0, int16_t y0, int16_t radius, uint8_t quads);
  virtual void fillCircle(int16_t x, int16_t y, int16_t radius);
  virtual void drawHorizontalLine(int16_t x, int16_t y, int16_t length);
  virtual void drawVerticalLine(int16_t x, int16_t y, int16_t length);

  // Image functions
  virtual void drawXbm(int16_t x, int16_t y, int16_t width, int16_t height, const char *xbm);

  // Text functions
  virtual void drawString(int16_t x, int16_t y, String text);
  virtual uint16_t getStringWidth(String text);
  virtual void setTextAlignment(DISPLAY_TEXT_ALIGNMENT textAlignment);
  virtual void setFont(const char *fontData);

  // Display functions
  virtual void flipScreenVertically();
  virtual void invertDisplay(void);
  virtual void normalDisplay(void);
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
