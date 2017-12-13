/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    30/09/2017 10:48*/
/* P-Name:  UIKit           */
/****************************/

#ifndef UILINE_H
#define UILINE_H

#include <Arduino.h>
#include "UIView.h"

class UILine: public UIView {
public:
  UILine();
  UILine(UIPoint origin, UIPoint end);
  virtual ~UILine();

  UIPoint end();

  virtual void draw(UIScreen *screen);

protected:
  UIPoint m_end;
};

#endif
