/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    07/09/2017 22:38*/
/* P-Name:  Smart Fish Tank */
/****************************/

#include "DisplaySSD1306.h"

DisplaySSD1306::DisplaySSD1306(uint8_t sda, uint8_t scl)
:m_sda(sda), m_scl(scl), m_display(0x3c, sda, scl)
{
  m_display.init();
}

DisplaySSD1306::~DisplaySSD1306()
{}
  

/*******************/
/* Image functions */
/*******************/
void DisplaySSD1306::drawXbm(int16_t x, int16_t y, int16_t width, int16_t height, const char *xbm) {
  m_display.drawXbm(x, y, width, height, xbm);
}


/******************/
/* Text functions */
/******************/
void DisplaySSD1306::drawString(int16_t x, int16_t y, String text) {
  m_display.drawString(x, y, text);
}

uint16_t DisplaySSD1306::getStringWidth(String text) {
  return m_display.getStringWidth(text);
}

void DisplaySSD1306::setTextAlignment(DISPLAY_TEXT_ALIGNMENT textAlignment) {
  m_display.setTextAlignment((OLEDDISPLAY_TEXT_ALIGNMENT)textAlignment);
}

void DisplaySSD1306::setFont(const char *fontData) {
  m_display.setFont(fontData);
}


/*********************/
/* Display functions */
/*********************/
void DisplaySSD1306::displayOn(void) {
  m_display.displayOn();
}

void DisplaySSD1306::displayOff(void) {
  m_display.displayOff();
}

void DisplaySSD1306::display(void) {
  m_display.display();
}

void DisplaySSD1306::clear(void) {
  m_display.clear();
}
