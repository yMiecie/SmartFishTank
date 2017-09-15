/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    07/09/2017 22:08*/
/* P-Name:  Smart Fish Tank */
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
