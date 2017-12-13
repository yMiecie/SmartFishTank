/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    27/09/2017 22:43*/
/* P-Name:  SmartFishTank   */
/****************************/

#ifndef BASECONTROLLER_H
#define BASECONTROLLER_H

#include <UIKit.h>
#include "../Services/DependenciesServices.h"

class BaseController {
public:
  BaseController();
  BaseController(DependenciesServices* dependenciesServices);
  virtual ~BaseController();

protected:
  DependenciesServices* m_$;
  UIViewController *m_nextVC = NULL;
};

class BaseViewController: public UIViewController, public BaseController {
  public:
    explicit BaseViewController(DependenciesServices* dependenciesServices);
    virtual ~BaseViewController();
};

class BaseNavigationViewController: public UINavigationViewController, public BaseController {
  public:
    explicit BaseNavigationViewController(DependenciesServices* dependenciesServices);
    explicit BaseNavigationViewController(DependenciesServices* dependenciesServices, UIViewController* rootViewController);
    virtual ~BaseNavigationViewController();
};

class BasePagerViewController: public UIPagerViewController, public BaseController {
  public:
    explicit BasePagerViewController(DependenciesServices* dependenciesServices);
    virtual ~BasePagerViewController();
};

#endif
