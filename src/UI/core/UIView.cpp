/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    08/09/2017 22:08*/
/* P-Name:  Smart Fish Tank */
/****************************/

#include "UIView.h"
#include <algorithm>

  UIView::UIView()
  :UIView(UIFrameZero())
  {}

  UIView::UIView(UIFrame frame)
  :frame(frame), type("UIView"), hiden(false), superView(NULL)
  {}

  UIView::~UIView()
  {}

  UIFrame UIView::getBounds() const {
    return UIFrameMake(0, 0, frame.size.width, frame.size.height);
  }

  UIPoint UIView::getScreenOrigin() {
    UIPoint origin = frame.origin;

    if (superView != NULL) {
      UIPoint super = superView->getScreenOrigin();
      origin.x += super.x;
      origin.y += super.y;
    }

    return origin;
  }

  void UIView::addSubview(UIView* subview) {
    subview->superView = this;
    subviews.push_back(subview);
  }

  void UIView::removeFromSuperView() {
    superView->subviews.erase(std::remove(superView->subviews.begin(), superView->subviews.end(), this), superView->subviews.end());
    superView = NULL;
  }

  void UIView::draw(Display* display) {

    if (hiden) {
      return ;
    }

    for(int i(0); i<subviews.size(); ++i)
    {
      UIView *subview = subviews[i];

      if (subview != NULL) {
       subviews[i]->draw(display);
      }
    }
  }
