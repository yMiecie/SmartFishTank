/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    07/09/2017 22:08*/
/* P-Name:  Smart Fish Tank */
/****************************/

#ifndef VIEWCONTROLLER_H
#define VIEWCONTROLLER_H

#include <Arduino.h>

class UIScreen;
class UIView;

class UIViewController {
public:
  UIViewController();
  ~UIViewController();

  UIView* view;

  void loop();

protected:
  virtual void viewDidLoad();
  virtual void viewWillAppear();
  virtual void viewDidAppear();
  virtual void viewWillDesappear();
  virtual void viewDidDesappear();

  UIScreen* m_screen;

  friend class UIScreen;

private:
  void loadView();
};

#endif
