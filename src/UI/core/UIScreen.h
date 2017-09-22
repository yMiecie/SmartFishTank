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

enum FrameState {
  IN_TRANSITION,
  FIXED
};

class UISize;

class UIScreen {
public:
  UIScreen(Display *display);
  ~UIScreen();

  UIViewController  *viewController;

  // Set update the Screen
  void setTargetFPS(uint8_t fps);

  // Update screen & return remaining time
  int8_t update();

  // Time from last update in ms
  uint64_t  lastUpdate();
  uint8_t   updateInterval();

  Display   *display() const;

  UISize    size();

private:
  Display           *m_display;
  UIViewController  *m_displayedViewController;

  // Bookeeping for update
  uint8_t             m_updateInterval      = 33; // ±30fps
  uint64_t            m_lastUpdate          = 0;

  void draw();
};

#endif
