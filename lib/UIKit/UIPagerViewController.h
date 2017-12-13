/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    07/09/2017 22:08*/
/* P-Name:  UIKit           */
/****************************/

#ifndef UIPAGEVIEWCONTROLLER_H
#define UIPAGEVIEWCONTROLLER_H

#include <Arduino.h>
#include <vector>

#include "UIViewController.h"

class UIPagerViewController: public UIViewController {
public:
  UIPagerViewController();
  virtual ~UIPagerViewController();

  bool loop;
  bool automaticTransition;
  float transitionInterval;

  uint16_t          currentIndex();
  UIViewController* currentViewController();
  std::vector<UIViewController*> viewControllers();
  virtual void next(bool animated);
  virtual void prev(bool animated);
  virtual void setTo(uint16_t index, bool animated);

  virtual void addViewControllers(UIViewController* viewController);
  virtual void removeViewControllers(UIViewController* viewController);

protected:
  virtual void viewDidLoad();
  virtual void viewWillAppear();
  virtual void viewDidAppear();
  virtual void viewWillDesappear();
  virtual void viewDidDesappear();
  virtual void viewWillUpdate();
  virtual void viewDidUpdate();

  uint16_t  m_currentIndex;
  long      m_currentTransitionAnimation;
  UIViewController  *m_currentViewController;
  std::vector<UIViewController*> m_viewControllers;
};
#endif
