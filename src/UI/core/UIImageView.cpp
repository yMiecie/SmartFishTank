/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    08/09/2017 22:08*/
/* P-Name:  Smart Fish Tank */
/****************************/

#include "UIImageView.h"

  UIImageView::UIImageView(UIImage *image)
  : UIView(UIFrameMake(UIPointZero(), image->size)), m_image(image)
  {
  }

  UIImageView::~UIImageView()
  {}

  void UIImageView::draw(Display* display) {
    UIView::draw(display);

    if (this->hiden) {
      return ;
    }

    UIPoint origin = this->getScreenOrigin();

    display->drawXbm(origin.x, origin.y, m_image->size.width, m_image->size.height, m_image->xbm);
  }
