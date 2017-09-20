/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    08/09/2017 22:08*/
/* P-Name:  Smart Fish Tank */
/****************************/

#include "UINavigationViewController.h"
#include "UIView.h"

UINavigationViewController::UINavigationViewController(UIViewController* viewController)
:UIViewController(), rootViewController(viewController), currentViewController(NULL)
{
  viewControllers.push_back(rootViewController);
}

void UINavigationViewController::viewDidLoad() {
  UIViewController::viewDidLoad();
  show(rootViewController, false, false);
}

void UINavigationViewController::viewWillAppear() {
  UIViewController::viewWillAppear();

  if (currentViewController != NULL) {
    currentViewController->viewWillAppear(); }
}

void UINavigationViewController::viewDidAppear() {
  UIViewController::viewDidAppear();

  if (currentViewController != NULL) {
    currentViewController->viewDidAppear(); }
}

void UINavigationViewController::viewWillDesappear() {
  UIViewController::viewWillDesappear();

  if (currentViewController != NULL) {
    currentViewController->viewWillDesappear(); }
}

void UINavigationViewController::viewDidDesappear() {
  UIViewController::viewDidDesappear();

  if (currentViewController != NULL) {
    currentViewController->viewDidDesappear(); }
}

void UINavigationViewController::pushViewController(UIViewController* viewController, boolean animated) {
  viewControllers.push_back(viewController);
  show(viewController, animated, true);
}

void UINavigationViewController::popViewController(boolean animated) {
  if ( viewControllers.size() <= 1) {
    return ;
  }

  viewControllers.pop_back();
  show(viewControllers.back(), animated, false);
}

void UINavigationViewController::popToRootViewController(boolean animated) {
    if ( viewControllers.size() <= 1) {
      return ;
    }

    while (viewControllers.back() != viewControllers.front())
    {
      viewControllers.pop_back();
    }
    show(viewControllers.back(), animated, false);
}

void UINavigationViewController::show(UIViewController* viewController, bool animated, bool useRightAnimation) {

  if (!animated) {

    if (currentViewController != NULL) {
      currentViewController->viewWillDesappear();
      currentViewController->view->removeFromSuperView();
      currentViewController->viewDidDesappear();
    }

    viewController->viewDidLoad();
    view->addSubview(viewController->view);
    currentViewController = viewController;
  }
}
