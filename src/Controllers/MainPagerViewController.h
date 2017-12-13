/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    30/09/2017 11:26*/
/* P-Name:  SmartFishTank   */
/****************************/

#ifndef MAINPAGERVIEWCONTROLLER_H
#define MAINPAGERVIEWCONTROLLER_H

#include "BaseController.h"

class MainPagerViewController: public BasePagerViewController {

public:
  using BasePagerViewController::BasePagerViewController;
  MainPagerViewController(DependenciesServices* dependenciesServices);
  virtual ~MainPagerViewController();

protected:
  virtual void viewDidLoad();
};

#endif
