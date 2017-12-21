/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    27/09/2017 19:07*/
/* P-Name:  SmartFishTank   */
/****************************/

#include <UIKit.h>
#include "SplashViewController.h"
#include "HomeViewController.h"

SplashViewController::~SplashViewController() {

  clearTimer();

  delete m_header;
  delete m_footer;
  delete m_image;
  delete m_imageView;
}

void SplashViewController::viewDidLoad() {
  BaseViewController::viewDidLoad();

  m_header = new UILabel("SMART FISH TANK");
  m_header->frame.origin.x = view->frame.size.width / 2;
  m_header->fontData = SansSerif_bold_10;
  m_header->textAlignment = UITEXT_ALIGNMENT::TEXT_ALIGN_CENTER;
  view->addSubview(m_header);

  UISize size = UISizeMake(SmartFish_width, SmartFish_height);
  m_image = new UIImage(size, SmartFish_bits);
  m_imageView = new UIImageView(m_image);
  m_imageView->frame.origin.x = (view->frame.size.width - SmartFish_width) / 2;
  m_imageView->frame.origin.y = 16;
  view->addSubview(m_imageView);

  m_footer = new UILabel("Developed by Y. Miecielica");
  m_footer->frame.origin.x = view->frame.size.width / 2;
  m_footer->frame.origin.y = view->frame.size.height - 12;
  m_footer->fontData = SansSerif_plain_8;
  m_footer->textAlignment = UITEXT_ALIGNMENT::TEXT_ALIGN_CENTER;
  view->addSubview(m_footer);
}

void SplashViewController::viewDidAppear() {
    BaseViewController::viewDidAppear();

    std::function<void (Timer *)> handler = [this](Timer *timer) {

    //  m_nextVC = new HomeNavigationViewController(m_$);
      HomeViewController *vc =  new HomeViewController(m_$);
      m_nextVC = vc;
      //m_nextVC = new UINavigationViewController(vc);
      m_nextVC->tag = "HomeViewController";
      m_nextVC->view->frame.size = view->frame.size;

      this->navigationController->pushViewController(m_nextVC, true);
    };

    clearTimer();

    m_timer = new Timer(3000, handler, false);
    m_$->timerController()->add(m_timer);
}

void SplashViewController::clearTimer() {
    if (m_timer != NULL) {
        m_$->timerController()->remove(m_timer->id);
        delete m_timer;
        m_timer = NULL;
    }
}
