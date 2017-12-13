/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    27/09/2017 22:43*/
/* P-Name:  SmartFishTank   */
/****************************/

#include "BaseController.h"

//
// Base
BaseController::BaseController()
: BaseController(NULL) { }

BaseController::BaseController(DependenciesServices* dependenciesServices)
: m_$(dependenciesServices) { }

BaseController::~BaseController() {
  if (m_nextVC != NULL) {
    delete m_nextVC;
  }
}

//
// BaseViewController
BaseViewController::BaseViewController(DependenciesServices* dependenciesServices)
: UIViewController(), BaseController(dependenciesServices) { }

BaseViewController::~BaseViewController() {
}

//
// BaseNavigationViewController
BaseNavigationViewController::BaseNavigationViewController(DependenciesServices* dependenciesServices)
: BaseNavigationViewController(dependenciesServices, NULL) { }

BaseNavigationViewController::BaseNavigationViewController(DependenciesServices* dependenciesServices, UIViewController* rootViewController)
: UINavigationViewController(rootViewController), BaseController(dependenciesServices) { }

BaseNavigationViewController::~BaseNavigationViewController() {
}

//
// BasePagerViewController
BasePagerViewController::BasePagerViewController(DependenciesServices* dependenciesServices)
: UIPagerViewController(), BaseController(dependenciesServices) { }

BasePagerViewController::~BasePagerViewController() {
}
