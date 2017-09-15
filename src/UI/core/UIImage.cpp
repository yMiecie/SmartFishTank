/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    08/09/2017 22:08*/
/* P-Name:  Smart Fish Tank */
/****************************/

#include "UIImage.h"

  UIImage::UIImage()
  :size(UISizeZero())
  {}

  UIImage::UIImage(UISize size, const char *xbm)
  :size(size), xbm(xbm)
  {}

  UIImage::~UIImage()
  {}
