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

class UINavigationViewController: public UIViewController {
public:
  UINavigationViewController(UIViewController* rootViewController);
  ~UINavigationViewController();

  UIViewController* rootViewController;
  UIViewController* currentViewController;
  std::vector<UIViewController*> viewControllers;
  void pushViewController(UIViewController* viewController, boolean animated);
  void popViewController(boolean animated);
  void popToRootViewController(boolean animated);

protected:
  virtual void viewDidLoad();
  virtual void viewWillAppear();
  virtual void viewDidAppear();
  virtual void viewWillDesappear();
  virtual void viewDidDesappear();

private:
  void loadView();
  void show(UIViewController* viewController, bool animated, bool useRightAnimation);
};

#endif
