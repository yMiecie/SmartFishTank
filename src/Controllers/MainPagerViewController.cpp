/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    30/09/2017 00:05*/
/* P-Name:  SmartFishTank   */
/****************************/

#include <UIKit.h>
#include "MainPagerViewController.h"

MainPagerViewController::MainPagerViewController(DependenciesServices* dependenciesServices)
:BasePagerViewController(dependenciesServices)
{
}

MainPagerViewController::~MainPagerViewController() {
}

void MainPagerViewController::viewDidLoad() {
  BasePagerViewController::viewDidLoad();
}
