/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    07/09/2017 22:08*/
/* P-Name:  Smart Fish Tank */
/****************************/

#ifndef UIVIEW_H
#define UIVIEW_H

#include <Arduino.h>
#include <functional>
#include <vector>
#include "UIScreen.h"

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

struct UIAnimation {
  uint32_t id = 0;
  float delay = 0;
  float duration = 0;
  uint32_t ticks = 0;
  uint16_t tickInterval = 33; // ± 30fps
  std::function< void (float)> animation = [](float progress) { };
  std::function< void (bool)> completion = [](bool cancelled) { };
};

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
  void removeFromSuperView();

  String type;

  bool hiden;
  virtual void draw(UIScreen* screen);

  // All animate function return the id of generated animation.
  // std::function< void (int)> animation :  No return value and takes a single integer value that is the progress factor (0.0->1.0)
  // std::function< void (bool)> completion :  No return value and takes a single Boolean argument that indicates whether or not the animations finished before the completion handler was called.
  long animate(float duration, std::function< void (float)> animation);
  long animate(float duration, float delay, std::function< void (float)> animation);
  long animate(float duration, std::function< void (float)> animation, std::function< void (bool)> completion);
  long animate(float duration, float delay, std::function< void (float)> animation, std::function< void (bool)> completion);

  // Take animation ID return by animate() and return bool, 0 if animation not found & 1 if animation was found and interupted.
  bool cancelAnimation(long animationId);

private:
  std::vector<UIAnimation> runningAnimations;
  void updateAnimations(UIScreen* screen);
};

#endif
