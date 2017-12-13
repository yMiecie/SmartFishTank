/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    07/09/2017 22:08*/
/* P-Name:  UIKit           */
/****************************/

#ifndef UINAVIGATIONVIEWCONTROLLER_H
#define UINAVIGATIONVIEWCONTROLLER_H

#include <Arduino.h>
#include <vector>

#include "UIViewController.h"

enum class UINAVIGATION_ANIMATION {
  NO_ANIMATION      = 0,
  ANIME_FROM_RIGHT,
  ANIME_FROM_LEFT,
  ANIME_FROM_BOTTOM,
  ANIME_FROM_TOP
};

class UINavigationViewController: public UIViewController {
public:
  UINavigationViewController();
  UINavigationViewController(UIViewController* rootViewController);
  virtual ~UINavigationViewController();

  UIView *header;
  UIView *footer;

  UIViewController* rootViewController();
  UIViewController* currentViewController();
  std::vector<UIViewController*> viewControllers();
  virtual void pushViewController(UIViewController* viewController, boolean animated);
  virtual void pushViewController(UIViewController* viewController, UINAVIGATION_ANIMATION animation);
  virtual void popViewController(boolean animated);
  virtual void popViewController(UINAVIGATION_ANIMATION animation);
  virtual void popToRootViewController(boolean animated);
  virtual void popToRootViewController(UINAVIGATION_ANIMATION animation);

protected:
  virtual void viewDidLoad();
  virtual void viewWillAppear();
  virtual void viewDidAppear();
  virtual void viewWillDesappear();
  virtual void viewDidDesappear();
  virtual void viewWillUpdate();
  virtual void viewDidUpdate();

  UIViewController* m_rootViewController;
  UIViewController* m_currentViewController;
  std::vector<UIViewController*> m_viewControllers;

private:
  virtual void show(UIViewController* viewController, UINAVIGATION_ANIMATION animation);
};

#endif
