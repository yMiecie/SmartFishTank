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

//
// Life Cycle
void UINavigationViewController::viewDidLoad() {
  UIViewController::viewDidLoad();
  show(rootViewController, UINAVIGATION_ANIMATION::NO_ANIMATION);
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

void UINavigationViewController::viewWillUpdate() {
  UIViewController::viewWillUpdate();

  if (currentViewController != NULL) {
    currentViewController->viewWillUpdate(); }
  if (currentViewController != viewControllers.back()) {
        viewControllers.back()->viewWillUpdate(); }
}

void UINavigationViewController::viewDidUpdate() {
  UIViewController::viewDidUpdate();

  if (currentViewController != NULL) {
    currentViewController->viewDidUpdate(); }
  if (currentViewController != viewControllers.back()) {
        viewControllers.back()->viewDidUpdate(); }
}

//
// Navigation
void UINavigationViewController::pushViewController(UIViewController* viewController, boolean animated) {
  pushViewController(viewController, animated ? UINAVIGATION_ANIMATION::ANIME_FROM_RIGHT : UINAVIGATION_ANIMATION::NO_ANIMATION);
}

void UINavigationViewController::pushViewController(UIViewController* viewController, UINAVIGATION_ANIMATION animation) {
  viewControllers.push_back(viewController);
  show(viewController, animation);
}

void UINavigationViewController::popViewController(boolean animated) {
  popViewController(animated ? UINAVIGATION_ANIMATION::ANIME_FROM_LEFT : UINAVIGATION_ANIMATION::NO_ANIMATION);
}

void UINavigationViewController::popViewController(UINAVIGATION_ANIMATION animation) {
  if ( viewControllers.size() <= 1) {
    return ;
  }

  viewControllers.pop_back();
  show(viewControllers.back(), animation);
}

void UINavigationViewController::popToRootViewController(boolean animated) {
    popToRootViewController(animated ? UINAVIGATION_ANIMATION::ANIME_FROM_LEFT : UINAVIGATION_ANIMATION::NO_ANIMATION);
}

void UINavigationViewController::popToRootViewController(UINAVIGATION_ANIMATION animation) {
    if ( viewControllers.size() <= 1) {
      return ;
    }

    while (viewControllers.back() != viewControllers.front()) {
      viewControllers.pop_back();
    }

    show(viewControllers.back(), animation);
}

void UINavigationViewController::show(UIViewController* viewController, UINAVIGATION_ANIMATION animation) {

  if (animation == UINAVIGATION_ANIMATION::NO_ANIMATION) {

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
