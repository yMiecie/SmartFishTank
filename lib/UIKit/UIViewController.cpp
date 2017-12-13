/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    08/09/2017 22:08*/
/* P-Name:  UIKit           */
/****************************/

#include "UIViewController.h"
#include "UINavigationViewController.h"
#include "UIPagerViewController.h"
#include "UIView.h"

UIViewController::UIViewController()
: view(NULL), navigationController(NULL),
  pagerController(NULL), m_screen(NULL),
  m_viewStatus(UIViewController::UIViewControllerStatus::notLoaded)
{
  view = new UIView();
}

UIViewController::~UIViewController() {
  delete view;
  view = NULL;
}

void UIViewController::viewDidLoad() {
  m_viewStatus = UIViewController::UIViewControllerStatus::didLoaded;
}

void UIViewController::viewWillAppear() {
    m_viewStatus = UIViewController::UIViewControllerStatus::willAppear;
}

void UIViewController::viewDidAppear() {
    m_viewStatus = UIViewController::UIViewControllerStatus::didAppear;
}

void UIViewController::viewWillDesappear() {
    m_viewStatus = UIViewController::UIViewControllerStatus::willDesappear;
}

void UIViewController::viewDidDesappear() {
    m_viewStatus = UIViewController::UIViewControllerStatus::desappear;
}

void UIViewController::viewWillUpdate() {
}

void UIViewController::viewDidUpdate() {
}
