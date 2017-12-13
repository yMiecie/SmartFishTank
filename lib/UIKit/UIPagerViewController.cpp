/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    08/09/2017 22:08*/
/* P-Name:  UIKit           */
/****************************/
#include "UIPagerViewController.h"
#include "UIView.h"

UIPagerViewController::UIPagerViewController()
:UIViewController(), automaticTransition(true), transitionInterval(3),
 m_currentIndex(0), m_currentTransitionAnimation(0), m_currentViewController(NULL)
{
}

UIPagerViewController::~UIPagerViewController() {
}

uint16_t UIPagerViewController::currentIndex() {
  return m_currentIndex;
}

UIViewController* UIPagerViewController::currentViewController() {
  return m_viewControllers[m_currentIndex];
}

std::vector<UIViewController*> UIPagerViewController::viewControllers() {
  return m_viewControllers;
}

//
// Life Cycle
void UIPagerViewController::viewDidLoad() {
  UIViewController::viewDidLoad();
}

void UIPagerViewController::viewWillAppear() {
  UIViewController::viewWillAppear();

  if (m_currentViewController != NULL) {
    m_currentViewController->viewWillAppear(); }
}

void UIPagerViewController::viewDidAppear() {
  UIViewController::viewDidAppear();

  if (m_currentViewController != NULL) {
    m_currentViewController->viewDidAppear(); }
}

void UIPagerViewController::viewWillDesappear() {
  UIViewController::viewWillDesappear();

  if (m_currentViewController != NULL) {
    m_currentViewController->viewWillDesappear(); }
}

void UIPagerViewController::viewDidDesappear() {
  UIViewController::viewDidDesappear();

  if (m_currentViewController != NULL) {
    m_currentViewController->viewDidDesappear(); }
}

void UIPagerViewController::viewWillUpdate() {
  UIViewController::viewWillUpdate();

  if (m_currentViewController != NULL) {
    m_currentViewController->viewWillUpdate(); }
  else if (m_viewControllers.size() > 0) {
    setTo(0, false);
  }
  if (m_currentViewController != m_viewControllers.back()) {
        m_viewControllers.back()->viewWillUpdate(); }
}

void UIPagerViewController::viewDidUpdate() {
  UIViewController::viewDidUpdate();

  if (m_currentViewController != NULL) {
    m_currentViewController->viewDidUpdate(); }
  if (m_currentViewController != m_viewControllers.back()) {
        m_viewControllers.back()->viewDidUpdate(); }
}

//
// Navigation
void UIPagerViewController::next(bool animated) {
  if (m_currentIndex + 1 < m_viewControllers.size()) {
    setTo(m_currentIndex + 1, animated);
  } else if (loop) {
      setTo(0, animated);
  }
}

void UIPagerViewController::prev(bool animated) {
    if (m_currentIndex - 1 > 0) {
      setTo(m_currentIndex - 1, animated);
    } else if (loop) {
        setTo((m_viewControllers.size() - 1), animated);
    }
}

void UIPagerViewController::addViewControllers(UIViewController* viewController) {
  viewController->pagerController = this;
  viewController->viewDidLoad();
  m_viewControllers.push_back(viewController);
}

void UIPagerViewController::removeViewControllers(UIViewController* viewController) {
  vector<UIViewController*>::iterator it;
  uint16_t index = 0;

  for( it=m_viewControllers.begin() ; it < m_viewControllers.end(); index++) {
      if ( (*it) == viewController) {
        (*it)->pagerController = NULL;
        it = m_viewControllers.erase(it);
        break;
      } else {
        ++it;
      }
  }
}

void UIPagerViewController::setTo(uint16_t index, bool animated) {

  if (index < 0 || index >= m_viewControllers.size() ||index == m_currentIndex) {
    return ;
  }

  UIViewController *viewController = m_viewControllers[index];

  if (!animated) {
    if (m_currentViewController != NULL) {
      m_currentViewController->viewWillDesappear();
      m_currentViewController->view->removeFromSuperView();
      m_currentViewController->viewDidDesappear();
    }
    view->addSubview(viewController->view);
    viewController->viewWillAppear();
    m_currentViewController = viewController;
    m_currentIndex = index;
    viewController->viewDidAppear();
  } else {
    std::function< void (bool)> completion = [index, viewController, this](bool finished) {
      if (this->m_currentViewController != NULL) {
        this->m_currentViewController->viewWillDesappear();
        this->m_currentViewController->view->removeFromSuperView();
        this->m_currentViewController->viewDidDesappear();
      }
      this->m_currentViewController = viewController;
      this->m_currentIndex = index;
      viewController->viewDidAppear();
    };
    view->addSubview(viewController->view);
    viewController->viewWillAppear();

    if (index > m_currentIndex) {
        viewController->view->frame.origin.x = this->view->frame.size.width;
        view->animate(0.3,
                      [viewController, this](float progress) {
                        float width = (float)this->view->frame.size.width;
                        viewController->view->frame.origin.x = (int16_t)(width * (1.0f - progress));
                        if (this->m_currentViewController != NULL) {
                          this->m_currentViewController->view->frame.origin.x = (int16_t)(-width * progress);
                        }
                      },
                      completion);
      } else {
          viewController->view->frame.origin.x = -this->view->frame.size.width;
          view->animate(0.3,
                        [viewController, this](float progress) {
                          float width = (float)this->view->frame.size.width;
                          viewController->view->frame.origin.x = (int16_t)(-width * (1.0f - progress));
                          if (this->m_currentViewController != NULL) {
                            this->m_currentViewController->view->frame.origin.x = (int16_t)(width * progress);
                          }
                        },
                        completion);
      }
    }
}
