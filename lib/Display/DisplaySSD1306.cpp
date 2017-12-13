/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    07/09/2017 22:38*/
/* P-Name:  Display         */
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
/* Size functions  */
/*******************/
int DisplaySSD1306::width() {
  return 128;
}

int DisplaySSD1306::height() {
  return 64;
}

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
/* Draw functions    */
/*********************/
void DisplaySSD1306::setPixel(int16_t x, int16_t y) {
  m_display.setPixel(x, y);
}

void DisplaySSD1306::drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1) {
  m_display.drawLine(x0, y0, x1, y1);
}

void DisplaySSD1306::drawRect(int16_t x, int16_t y, int16_t width, int16_t height) {
  m_display.drawRect(x, y, width, height);
}

void DisplaySSD1306::fillRect(int16_t x, int16_t y, int16_t width, int16_t height) {
  m_display.fillRect(x, y, width, height);
}

void DisplaySSD1306::drawCircle(int16_t x, int16_t y, int16_t radius) {
  m_display.drawCircle(x, y, radius);
}

void DisplaySSD1306::drawCircleQuads(int16_t x0, int16_t y0, int16_t radius, uint8_t quads) {
  m_display.drawCircleQuads(x0, y0, radius, quads);
}

void DisplaySSD1306::fillCircle(int16_t x, int16_t y, int16_t radius) {
  m_display.fillCircle(x, y, radius);
}

void DisplaySSD1306::drawHorizontalLine(int16_t x, int16_t y, int16_t length) {
  m_display.drawHorizontalLine(x, y, length);
}

void DisplaySSD1306::drawVerticalLine(int16_t x, int16_t y, int16_t length) {
  m_display.drawHorizontalLine(x, y, length);
}

/*********************/
/* Display functions */
/*********************/
void DisplaySSD1306::flipScreenVertically(){
  m_display.flipScreenVertically();
}

void DisplaySSD1306::invertDisplay(void){
    m_display.invertDisplay();
}

void DisplaySSD1306::normalDisplay(void) {
  m_display.normalDisplay();
}

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
