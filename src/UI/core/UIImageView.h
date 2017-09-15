/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    07/09/2017 22:08*/
/* P-Name:  Smart Fish Tank */
/****************************/

#ifndef UIIMAGEVIEW_H
#define UIIMAGEVIEW_H

#include <Arduino.h>
#include "UIView.h"
#include "UIImage.h"

class UIImageView: public UIView  {
public:
  UIImageView(UIImage *image);
  ~UIImageView();

  void setImage(UIImage *image);

  virtual void draw(Display* display);

protected:
  UIImage *m_image;
};

#endif
