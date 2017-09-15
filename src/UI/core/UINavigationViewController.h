/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    07/09/2017 22:08*/
/* P-Name:  Smart Fish Tank */
/****************************/

#ifndef UINAVIGATIONVIEWCONTROLLER_H
#define UINAVIGATIONVIEWCONTROLLER_H

#include <Arduino.h>

class UIViewController

class UINavigationViewController {
public:
  UINavigationViewController(UIViewController* rootViewController);
  ~UINavigationViewController();

  UIViewController* rootViewController;
  UIViewController* currentViewController;
  std::vector<UIViewController*> viewControllers;
  void pushViewController(UIViewController* viewController, boolean animated);
  void popViewController(boolean animated);
  void popToRootViewController(boolean animated);

private:
  void loadView();
};

#endif

#endif
