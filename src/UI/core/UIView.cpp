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

  void UIView::draw(UIScreen* screen) {

    if (hiden) {
      return ;
    }

    for(int i(0); i<subviews.size(); ++i)
    {
      UIView *subview = subviews[i];

      if (subview != NULL) {
       subviews[i]->draw(screen);
      }
    }

    updateAnimations(screen);
  }

  //
  // Animations
  long UIView::animate(float duration, std::function< void (float)> animation) {
    animate(duration, 0, animation,  [](bool cancelled) { });
  }

  long UIView::animate(float duration, float delay, std::function< void (float)> animation) {
    animate(duration, delay, animation,  [](bool cancelled) { });
  }

  long UIView::animate(float duration, std::function< void (float)> animation, std::function< void (bool)> completion) {
    animate(duration, 0, animation,  completion);
  }

  long UIView::animate(float duration, float delay, std::function< void (float)> animation, std::function< void (bool)> completion) {
    UIAnimation anim = UIAnimation();

    anim.id = millis();
    anim.delay = delay;
    anim.duration = duration;
    anim.animation = animation;
    anim.completion = completion;

    runningAnimations.push_back(anim);
  }

  bool UIView::cancelAnimation(long animationId) {
    vector<UIAnimation>::iterator it;
    bool retVal = false;

    for( it=runningAnimations.begin() ; it < runningAnimations.end(); ) {
        if ( it->id == animationId) {
          it->completion(false);
          it = runningAnimations.erase(it);
          retVal = true;
          break;
        } else {
          ++it;
        }
    }
    return retVal;
  }

  void UIView::updateAnimations(UIScreen *screen) {
    vector<UIAnimation>::iterator it;

    for( it=runningAnimations.begin() ; it < runningAnimations.end(); ) {

      // Update ticks if framerate change
      if (screen->updateInterval() != it->tickInterval) {
        float ratio = (float)it->tickInterval / (float)screen->updateInterval();
        it->ticks *= ratio;
        it->tickInterval  = screen->updateInterval();
      }

      // update tick count
      it->ticks++;

      // Skip animation if delay not past.
      uint32_t tickDelay = (uint32_t)(it->delay * (float)it->tickInterval);
      if (it->ticks < tickDelay) {
        ++it;
        continue;
      }

      // Remove finished animation
      uint32_t tickDuration = (uint32_t)(it->duration * (float)it->tickInterval);
      if ( it->ticks >=  tickDelay + tickDuration) {
        it->animation(1);
        it->completion(true);
        it = runningAnimations.erase(it);
        continue;
      }

      // Update animation with progress factor
      float progress = (float)(it->ticks - tickDelay) / (float)tickDuration;
      it->animation( progress );
      ++it;
    }
  }
