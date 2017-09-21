/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    07/09/2017 22:08*/
/* P-Name:  Smart Fish Tank */
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
  UINavigationViewController(UIViewController* rootViewController);
  ~UINavigationViewController();

  UIViewController* rootViewController;
  UIViewController* currentViewController;
  std::vector<UIViewController*> viewControllers;
  void pushViewController(UIViewController* viewController, boolean animated);
  void pushViewController(UIViewController* viewController, UINAVIGATION_ANIMATION animation);
  void popViewController(boolean animated);
  void popViewController(UINAVIGATION_ANIMATION animation);
  void popToRootViewController(boolean animated);
  void popToRootViewController(UINAVIGATION_ANIMATION animation);

protected:
  virtual void viewDidLoad();
  virtual void viewWillAppear();
  virtual void viewDidAppear();
  virtual void viewWillDesappear();
  virtual void viewDidDesappear();
  virtual void viewWillUpdate();
  virtual void viewDidUpdate();

private:
  void loadView();
  void show(UIViewController* viewController, UINAVIGATION_ANIMATION animation);
};

#endif
