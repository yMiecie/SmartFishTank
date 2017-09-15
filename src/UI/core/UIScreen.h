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

// Structure of the UiState
struct DisplayUiState {
  uint64_t     lastUpdate                = 0;
  uint16_t      ticksSinceLastStateSwitch = 0;

  FrameState    frameState                = FIXED;
  uint8_t       currentFrame              = 0;

  bool          isIndicatorDrawen         = true;

  // Normal = 1, Inverse = -1;
  int8_t        frameTransitionDirection  = 1;

  bool          manuelControll            = false;

  // Custom data that can be used by the user
  void*         userData                  = NULL;
};

class UIScreen {
public:
  UIScreen(Display *display);
  ~UIScreen();

  UIViewController  *viewController;

  // Set update the Screen
  void setTargetFPS(uint8_t fps);

  // Update screen & return remaining time
  int8_t update();

private:
  Display           *m_display;
  DisplayUiState     m_state;
  UIViewController  *m_displayedViewController;

  // Bookeeping for update
  uint8_t             m_updateInterval      = 33;
  uint16_t            m_ticksPerFrame       = 151; // ~ 5000ms at 30 FPS

  void draw();
};

#endif
