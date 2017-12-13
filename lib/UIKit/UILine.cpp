/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    30/09/2017 10:51*/
/* P-Name:  UIKit           */
/****************************/

#include "UILine.h"

  UILine::UILine()
  :UILine(UIPointZero(), UIPointZero())
  {}

  UILine::UILine(UIPoint origin, UIPoint end)
  :UIView(), m_end(end)
  {
    this->type = "UILine";
    frame.origin = origin;
    frame.size.width = m_end.x - origin.x;
    frame.size.height = m_end.y - origin.y;
  }

  UILine::~UILine()
  {}

  UIPoint UILine::end() {
    return m_end;
  }

  void UILine::draw(UIScreen* screen) {
    UIView::draw(screen);

    if (this->hiden) {
      return ;
    }

    UIPoint origin = this->getScreenOrigin();

    screen->display()->drawLine(origin.x, origin.y, origin.x + frame.size.width, origin.y + frame.size.height);
  }
