/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    08/09/2017 22:08*/
/* P-Name:  Smart Fish Tank */
/****************************/

#include "UIViewController.h"
#include "UIView.h"

UIViewController::UIViewController() {
  loadView();
}

UIViewController::~UIViewController() {
  delete view;
  view = NULL;
}

void UIViewController::loadView() {
  view = new UIView();
}

void UIViewController::viewDidLoad() {
}

void UIViewController::viewWillAppear() {
}

void UIViewController::viewDidAppear() {
}

void UIViewController::viewWillDesappear() {
}

void UIViewController::viewDidDesappear() {
}

void UIViewController::loop() {

}
