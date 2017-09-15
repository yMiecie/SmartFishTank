/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    08/09/2017 22:08*/
/* P-Name:  Smart Fish Tank */
/****************************/

#include "UINavigationViewController.h"

UINavigationViewController::UINavigationViewController(UIViewController* viewController)
:UIViewController()
{
  viewControllers.push_back(viewController);
}

void UINavigationViewController::viewDidLoad(){
  show(currentViewController, false);
}

void show(UIViewController* viewController, bool animated) {
  
}
