/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    07/09/2017 22:08*/
/* P-Name:  Smart Fish Tank */
/****************************/

#ifndef UIIMAGE_H
#define UIIMAGE_H

#include <Arduino.h>
#include "UIView.h"

class UIImage {
public:
  UIImage();
  UIImage(UISize size, const char *xbm);
  ~UIImage();

  const char  *xbm;
  UISize      size;
};

#endif
