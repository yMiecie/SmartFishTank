/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    27/09/2017 19:07*/
/* P-Name:  SmartFishTank   */
/****************************/

#ifndef SPLASHVIEWCONTROLLER_H
#define SPLASHVIEWCONTROLLER_H

#include "UIKit.h"
#include "BaseController.h"

class SplashViewController: public BaseViewController {

public:
  using BaseViewController::BaseViewController;
  virtual ~SplashViewController();

protected:
  virtual void viewDidLoad();
  virtual void viewDidAppear();
  void clearTimer();

  Timer   *m_timer = NULL;
  UILabel *m_header = NULL;
  UILabel *m_footer = NULL;
  UIImage *m_image = NULL;
  UIImageView *m_imageView = NULL;
};

#endif
