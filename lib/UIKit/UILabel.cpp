/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    08/09/2017 22:08*/
/* P-Name:  UIKit           */
/****************************/

#include "UILabel.h"

  UILabel::UILabel()
  :UILabel("")
  {}

  UILabel::UILabel(String text)
  :UIView(), text(text), fontData(nullptr), textAlignment(UITEXT_ALIGNMENT::TEXT_ALIGN_CENTER)
  {
    this->type = "UILabel";
  }

  UILabel::~UILabel()
  {}

  void UILabel::draw(UIScreen* screen) {
    UIView::draw(screen);

    if (this->hiden) {
      return ;
    }

    UIPoint origin = this->getScreenOrigin();

    if (fontData != nullptr)
      screen->display()->setFont(fontData);
    if (fontData != NULL)
      screen->display()->setTextAlignment((DISPLAY_TEXT_ALIGNMENT)textAlignment);

    screen->display()->drawString(origin.x, origin.y, text);
  }
