/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    07/09/2017 22:08*/
/* P-Name:  Smart Fish Tank */
/****************************/

#ifndef UISCREEN_H
#define UISCREEN_H

#include <Arduino.h>
#include "../../Display/Display.h"
#include "UIViewController.h"

class UIScreen {
public:
  UIScreen(Display *display);
  ~UIScreen();

  UIViewController  *viewController;

  // Set update the Screen
  void update();

private:
  Display           *m_display;
  UIViewController  *m_displayedViewController;

  // Bookeeping for update
  uint8_t             m_updateInterval      = 33;
  uint16_t            m_ticksPerFrame       = 151; // ~ 5000ms at 30 FPS
};

#endif
