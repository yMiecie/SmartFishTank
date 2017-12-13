/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    07/09/2017 22:08*/
/* P-Name:  Display         */
/****************************/

#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>

enum class DISPLAY_TEXT_ALIGNMENT {
  TEXT_ALIGN_LEFT = 0,
  TEXT_ALIGN_RIGHT = 1,
  TEXT_ALIGN_CENTER = 2,
  TEXT_ALIGN_CENTER_BOTH = 3
};

class Display {
public:

  /*******************/
  /* Size functions */
  /*******************/
  virtual int width() = 0;
  virtual int height() = 0;

  /*********************/
  /* Draw functions */
  /*********************/
  // Draw a pixel at given position
  virtual void setPixel(int16_t x, int16_t y) = 0;

  // Draw a line from position 0 to position 1
  virtual void drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1) = 0;

  // Draw the border of a rectangle at the given location
  virtual void drawRect(int16_t x, int16_t y, int16_t width, int16_t height) = 0;

  // Fill the rectangle
  virtual void fillRect(int16_t x, int16_t y, int16_t width, int16_t height) = 0;

  // Draw the border of a circle
  virtual void drawCircle(int16_t x, int16_t y, int16_t radius) = 0;

  // Draw all Quadrants specified in the quads bit mask
  virtual void drawCircleQuads(int16_t x0, int16_t y0, int16_t radius, uint8_t quads) = 0;

  // Fill circle
  virtual void fillCircle(int16_t x, int16_t y, int16_t radius) = 0;

  // Draw a line horizontally
  virtual void drawHorizontalLine(int16_t x, int16_t y, int16_t length) = 0;

  // Draw a lin vertically
  virtual void drawVerticalLine(int16_t x, int16_t y, int16_t length) = 0;

  /*******************/
  /* Image functions */
  /*******************/
  // Draw a XBM
  virtual void drawXbm(int16_t x, int16_t y, int16_t width, int16_t height, const char *xbm) = 0;


  /******************/
  /* Text functions */
  /******************/
  // Draws a string at the given location
  virtual void drawString(int16_t x, int16_t y, String text) = 0;

  // Convencience method for the const char version
  virtual uint16_t getStringWidth(String text) = 0;

  // Specifies relative to which anchor point
  // the text is rendered. Available constants:
  // TEXT_ALIGN_LEFT, TEXT_ALIGN_CENTER, TEXT_ALIGN_RIGHT, TEXT_ALIGN_CENTER_BOTH
  virtual void setTextAlignment(DISPLAY_TEXT_ALIGNMENT textAlignment) = 0;

  // Sets the current font. Available default fonts
  // ArialMT_Plain_10, ArialMT_Plain_16, ArialMT_Plain_24
  virtual void setFont(const char *fontData) = 0;


  /*********************/
  /* Display functions */
  /*********************/
  // Turn the display upside down
  virtual void flipScreenVertically() = 0;

  // Inverted display mode
  virtual void invertDisplay(void) = 0;

  // Normal display mode
  virtual void normalDisplay(void) = 0;

  // Turn the display on
  virtual void displayOn(void) = 0;

  // Turn the display offs
  virtual void displayOff(void) = 0;

  // Write the buffer to the display memory
  virtual void display(void) = 0;

  // Clear the local pixel buffer
  virtual void clear(void) = 0;
};

#endif
