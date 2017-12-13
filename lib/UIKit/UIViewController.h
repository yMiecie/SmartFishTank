/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    07/09/2017 22:08*/
/* P-Name:  UIKit           */
/****************************/

#ifndef VIEWCONTROLLER_H
#define VIEWCONTROLLER_H

#include <Arduino.h>

class UIScreen;
class UIView;
class UINavigationViewController;
class UIPagerViewController;

class UIViewController {

public:

  enum UIViewControllerStatus {
    notLoaded = 0,
    didLoaded,
    willAppear,
    didAppear,
    willDesappear,
    desappear
  };

  UIViewController();
  virtual ~UIViewController();

  String  tag;
  UIView* view;
  UINavigationViewController* navigationController;
  UIPagerViewController*      pagerController;

protected:
  virtual void viewDidLoad();
  virtual void viewWillAppear();
  virtual void viewDidAppear();
  virtual void viewWillDesappear();
  virtual void viewDidDesappear();
  virtual void viewWillUpdate();
  virtual void viewDidUpdate();

  UIScreen                  *m_screen;
  UIViewControllerStatus    m_viewStatus;

  friend class UIScreen;
  friend class UINavigationViewController;
  friend class UIPagerViewController;
};

#endif
