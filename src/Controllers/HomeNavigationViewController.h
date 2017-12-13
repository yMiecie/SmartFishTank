/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    28/09/2017 00:02*/
/* P-Name:  SmartFishTank   */
/****************************/

#ifndef HOMENAVIGATIONVIEWCONTROLLER_H
#define HOMENAVIGATIONVIEWCONTROLLER_H

#include "BaseController.h"

class HomeNavigationViewController: public BaseNavigationViewController {

public:
  //using BaseViewController::BaseNavigationViewController;
  HomeNavigationViewController(DependenciesServices* dependenciesServices);
  virtual ~HomeNavigationViewController();

  // Footer
  UILine      *topLine = NULL;
  UILabel     *button01Label = NULL;
  UIImageView *button01ImageView = NULL;
  UILabel     *button02Label = NULL;
  UIImageView *button02ImageView = NULL;
  UILabel     *button03Label = NULL;
  UIImageView *button03ImageView = NULL;

protected:
  virtual void viewDidLoad();

  // Header
  /*UILabel     *m_temperatureLabel = NULL;
  UIImage     *m_temperatureImage = NULL;
  UIImageView *m_temperatureImageView = NULL;
  UILabel     *m_phLabel = NULL;
  UIImage     *m_phImage = NULL;
  UIImageView *m_phImageView = NULL;*/
};

#endif
