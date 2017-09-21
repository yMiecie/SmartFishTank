/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    07/09/2017 22:08*/
/* P-Name:  Smart Fish Tank */
/****************************/

#ifndef UILABEL_H
#define UILABEL_H

#include <Arduino.h>
#include "UIView.h"

enum class UITEXT_ALIGNMENT {
  TEXT_ALIGN_LEFT = 0,
  TEXT_ALIGN_RIGHT = 1,
  TEXT_ALIGN_CENTER = 2,
  TEXT_ALIGN_CENTER_BOTH = 3
};

class UILabel: public UIView {
public:
  UILabel();
  UILabel(String text);
  ~UILabel();

  String text;
  const char *fontData;
  UITEXT_ALIGNMENT textAlignment;

  virtual void draw(UIScreen *screen);
};

#endif
