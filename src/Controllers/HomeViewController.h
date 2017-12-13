/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    09/12/2017 00:02*/
/* P-Name:  SmartFishTank   */
/****************************/

#ifndef HOMEVIEWCONTROLLER_H
#define HOMEVIEWCONTROLLER_H

#include "BaseController.h"

class HomeViewController: public BaseViewController {

public:
  HomeViewController(DependenciesServices* dependenciesServices);
  virtual ~HomeViewController();

protected:
  virtual void viewDidLoad();
  virtual void viewDidAppear();
  virtual void viewDidUpdate();
  void clearTimer();

  Timer       *m_timer = NULL;
  
  // Header
  UILabel     *m_temperatureLabel = NULL;
  UIImage     *m_temperatureImage = NULL;
  UIImageView *m_temperatureImageView = NULL;

  UILabel     *m_phLabel = NULL;
  UIImage     *m_phImage = NULL;
  UIImageView *m_phImageView = NULL;

  // Body
  UIImage     *m_heaterImage = NULL;
  UIImageView *m_heaterImageView = NULL;
  UILabel     *m_heaterStatusLabel = NULL;

  UIImage     *m_fanImage = NULL;
  UIImageView *m_fanImageView = NULL;
  UILabel     *m_fanStatusLabel = NULL;

  UIImage     *m_valveImage = NULL;
  UIImageView *m_valveImageView = NULL;
  UILabel     *m_valveStatusLabel = NULL;

  UIImage     *m_pumpImage = NULL;
  UIImageView *m_pumpImageView = NULL;
  UILabel     *m_pumpStatusLabel = NULL;
};

#endif
