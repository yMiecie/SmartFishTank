/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    08/09/2017 22:08*/
/* P-Name:  Smart Fish Tank */
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

  void UILabel::draw(Display* display) {
    UIView::draw(display);

    if (this->hiden) {
      return ;
    }

    UIPoint origin = this->getScreenOrigin();

    if (fontData != nullptr)
      display->setFont(fontData);
    if (fontData != NULL)
      display->setTextAlignment((DISPLAY_TEXT_ALIGNMENT)textAlignment);

    display->drawString(origin.x, origin.y, text);
  }
