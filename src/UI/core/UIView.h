/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    07/09/2017 22:08*/
/* P-Name:  Smart Fish Tank */
/****************************/

#ifndef UIVIEW_H
#define UIVIEW_H

#include <Arduino.h>
#include <vector>
#include "../../Display/Display.h"

using namespace std;

struct UIPoint {
  int16_t x;
  int16_t y;
};
inline UIPoint UIPointZero() { UIPoint point; point.x = point.y = 0; return point; }
inline UIPoint UIPointMake(int16_t x, int16_t y) { UIPoint point; point.x = x; point.y = y; return point; }

struct UISize {
  int16_t width;
  int16_t height;
};
inline UISize UISizeZero() { UISize size; size.width = size.height = 0; return size; }
inline UISize UISizeMake(int16_t width, int16_t height) { UISize size; size.width = width; size.height = height; return size; }

struct UIFrame {
  UIPoint origin;
  UISize  size;
};
inline UIFrame UIFrameZero() { UIFrame frame; frame.origin = UIPointZero(); frame.size = UISizeZero(); return frame; }
inline UIFrame UIFrameMake(UIPoint origin, UISize size) { UIFrame frame; frame.origin = origin; frame.size = size; return frame; }
inline UIFrame UIFrameMake(int16_t x, int16_t y, int16_t width, int16_t height) { UIFrame frame; frame.origin = UIPointMake(x, y); frame.size = UISizeMake(width, height); return frame; }

class UIView {
public:
  UIView();
  UIView(UIFrame frame);
  ~UIView();

  UIFrame frame;
  UIFrame getBounds() const;
  UIPoint getScreenOrigin();

  UIView* superView;
  std::vector<UIView*> subviews;
  void addSubview(UIView* subview);

  String type;

  bool hiden;
  virtual void draw(Display* display);
};

#endif
