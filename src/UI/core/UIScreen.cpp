/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    08/09/2017 22:08*/
/* P-Name:  Smart Fish Tank */
/****************************/

#include "../../Display/Display.h"
#include "UIScreen.h"
#include "UIView.h"

UIScreen::UIScreen(Display *display)
:m_display(display), m_displayedViewController(NULL)
{}

UIScreen::~UIScreen()
{}

void UIScreen::setTargetFPS(uint8_t fps){
  float oldInterval = m_updateInterval;
  m_updateInterval = ((float) 1.0 / (float) fps) * 1000;

  // Calculate new ticksPerFrame
  float changeRatio = oldInterval / (float) updateInterval;
  ticksPerFrame *= changeRatio;
}

void UIScreen::update() {

  if (m_displayedViewController != viewController)
  {

    if (m_displayedViewController != NULL) {
      // Remove displayed
      m_displayedViewController->viewWillDesappear();
      m_display->clear();
      m_displayedViewController->viewDidDesappear();
      delete m_displayedViewController;
      m_displayedViewController = NULL;
    }

    // Display new one
    if (viewController != NULL) {
      viewController->m_screen = this;
      viewController->viewDidLoad();
      viewController->viewWillAppear();
      if (viewController->view != NULL) {
        viewController->view->draw(m_display);
      }
      m_display->display();
      viewController->viewDidAppear();
      m_displayedViewController = viewController;
    }
  } else {
    // update current display
    m_display->clear();
    if (viewController != NULL && viewController->view != NULL) {
      viewController->view->draw(m_display);
    }
    m_display->display();
  }

  delay(10);
}


int8_t UIScreen::update(){
  long frameStart = millis();
  int8_t timeBudget = m_updateInterval - (frameStart - m_state.lastUpdate);
  if ( timeBudget <= 0) {
    // Implement frame skipping to ensure time budget is keept
    if (m_state.lastUpdate != 0) m_state.ticksSinceLastStateSwitch += ceil(-timeBudget / m_updateInterval);

    m_state.lastUpdate = frameStart;
    tick();
  }
  return m_updateInterval - (millis() - frameStart);
}
