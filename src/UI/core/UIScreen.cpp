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

Display *UIScreen::display() const {
  return m_display;
}

UISize UIScreen::size() {
  return UISizeMake(m_display->width(), m_display->height());
}

void UIScreen::setTargetFPS(uint8_t fps) {
  m_updateInterval = ((float) 1.0 / (float) fps) * 1000;
}

int8_t UIScreen::update(){
  long frameStart = millis();
  int8_t timeBudget = m_updateInterval - (frameStart - m_lastUpdate);
  if ( timeBudget <= 0) {
    m_lastUpdate = frameStart;
    draw();
  }
  return m_updateInterval - (millis() - frameStart);
}

uint64_t UIScreen::lastUpdate() {
  return m_lastUpdate;
}

uint8_t UIScreen::updateInterval() {
  return m_updateInterval;
}

void UIScreen::draw() {

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
        viewController->viewWillUpdate();
        viewController->view->draw(this);
        viewController->viewDidUpdate();
      }
      m_display->display();
      viewController->viewDidAppear();
      m_displayedViewController = viewController;
    }
  } else {
    // update current display
    m_display->clear();
    if (viewController != NULL && viewController->view != NULL) {
      viewController->viewWillUpdate();
      viewController->view->draw(this);
      viewController->viewDidUpdate();
    }
    m_display->display();
  }
}
