/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    08/09/2017 22:08*/
/* P-Name:  UIKit           */
/****************************/

#include "UINavigationViewController.h"
#include "UIView.h"

UINavigationViewController::UINavigationViewController()
: UINavigationViewController(NULL)
{
}

UINavigationViewController::UINavigationViewController(UIViewController* viewController)
:UIViewController(), m_rootViewController(viewController), m_currentViewController(NULL)
{
  // Header
  UIFrame frame = view->getBounds();
  frame.size.height = 12;
  header = new UIView(frame);
  header->hiden = true;
  view->addSubview(header);

  // Footer
  frame = view->getBounds();
  frame.size.height = 16;
  frame.origin.y -= frame.size.height;
  footer = new UIView(frame);
  footer->hiden = true;
  view->addSubview(footer);
}

UINavigationViewController::~UINavigationViewController() {
}

UIViewController* UINavigationViewController::rootViewController() {
  return m_rootViewController;
}

UIViewController* UINavigationViewController::currentViewController() {
  return m_currentViewController;
}

std::vector<UIViewController*> UINavigationViewController::viewControllers() {
  return m_viewControllers;
}

//
// Life Cycle
void UINavigationViewController::viewDidLoad() {
  UIViewController::viewDidLoad();

    if (m_rootViewController != NULL) {
      pushViewController(m_rootViewController, UINAVIGATION_ANIMATION::NO_ANIMATION); }
}


/*
notLoaded = 0,
didLoaded = 1,
willAppear = 2,
didAppear = 3,
willDesappear = 4,
desappear = 5
*/

void UINavigationViewController::viewWillAppear() {
  UIViewController::viewWillAppear();

  // Serial.printf("[UINavigationViewController::viewWillAppear] m_currentViewController: %s - %d (expect: 1/5)\n", m_currentViewController == NULL ? "NULL" : "NOT-NULL", m_currentViewController->m_viewStatus);

  if (m_currentViewController != NULL &&
      ( m_currentViewController->m_viewStatus == didLoaded ||
        m_currentViewController->m_viewStatus == desappear )) {
    m_currentViewController->viewWillAppear(); }
}

void UINavigationViewController::viewDidAppear() {
  UIViewController::viewDidAppear();

  // Serial.printf("[UINavigationViewController::viewDidAppear] m_currentViewController: %s - %d (expect: 2)\n", m_currentViewController == NULL ? "NULL" : "NOT-NULL", m_currentViewController->m_viewStatus);

  if (m_currentViewController != NULL &&
      m_currentViewController->m_viewStatus == willAppear ) {
    m_currentViewController->viewDidAppear(); }
}

void UINavigationViewController::viewWillDesappear() {
  UIViewController::viewWillDesappear();

  // Serial.printf("[UINavigationViewController::viewWillDesappear] m_currentViewController: %s - %d (expect: 3)\n", m_currentViewController == NULL ? "NULL" : "NOT-NULL", m_currentViewController->m_viewStatus);

  if (m_currentViewController != NULL &&
      m_currentViewController->m_viewStatus == didAppear ) {
    m_currentViewController->viewWillDesappear(); }
}

void UINavigationViewController::viewDidDesappear() {
  UIViewController::viewDidDesappear();

  // Serial.printf("[UINavigationViewController::viewDidDesappear] m_currentViewController: %s - %d (expect: 4)\n", m_currentViewController == NULL ? "NULL" : "NOT-NULL", m_currentViewController->m_viewStatus);

  if (m_currentViewController != NULL &&
      m_currentViewController->m_viewStatus == willDesappear ) {
    m_currentViewController->viewDidDesappear(); }
}

void UINavigationViewController::viewWillUpdate() {
  UIViewController::viewWillUpdate();

  if (m_currentViewController != NULL) {
    m_currentViewController->viewWillUpdate(); }
  if (m_currentViewController != m_viewControllers.back()) {
        m_viewControllers.back()->viewWillUpdate(); }
}

void UINavigationViewController::viewDidUpdate() {
  UIViewController::viewDidUpdate();

  if (m_currentViewController != NULL) {
    m_currentViewController->viewDidUpdate(); }
  if (m_currentViewController != m_viewControllers.back()) {
        m_viewControllers.back()->viewDidUpdate(); }
}

//
// Navigation
void UINavigationViewController::pushViewController(UIViewController* viewController, boolean animated) {
  pushViewController(viewController, animated ? UINAVIGATION_ANIMATION::ANIME_FROM_RIGHT : UINAVIGATION_ANIMATION::NO_ANIMATION);
}

void UINavigationViewController::pushViewController(UIViewController* viewController, UINAVIGATION_ANIMATION animation) {

  m_viewControllers.push_back(viewController);

  viewController->navigationController = this;

  UIFrame frame = view->getBounds();

  header->frame.size.width = frame.size.width;
  footer->frame.size.width = frame.size.width;
  footer->frame.origin.y = frame.size.height - footer->frame.size.height;
  if (!header->hiden) {
    frame.origin.y = header->frame.origin.y + header->frame.size.height;
    frame.size.height -= frame.origin.y;
  }
  if (!footer->hiden) {
    frame.size.height = footer->frame.origin.y - frame.origin.y;
  }

  viewController->view->frame = frame;

  //Serial.printf("[UINavigationViewController::pushViewController] viewController: %s - %d (expect: 0)\n", viewController == NULL ? "NULL" : "NOT-NULL", viewController->m_viewStatus);

  if (viewController->m_viewStatus == notLoaded)
      viewController->viewDidLoad();

  show(viewController, animation);
}

void UINavigationViewController::popViewController(boolean animated) {
  popViewController(animated ? UINAVIGATION_ANIMATION::ANIME_FROM_LEFT : UINAVIGATION_ANIMATION::NO_ANIMATION);
}

void UINavigationViewController::popViewController(UINAVIGATION_ANIMATION animation) {
  if ( m_viewControllers.size() <= 1) {
    return ;
  }

  m_viewControllers.back()->navigationController = NULL;
  m_viewControllers.pop_back();
  show(m_viewControllers.back(), animation);
}

void UINavigationViewController::popToRootViewController(boolean animated) {
    popToRootViewController(animated ? UINAVIGATION_ANIMATION::ANIME_FROM_LEFT : UINAVIGATION_ANIMATION::NO_ANIMATION);
}

void UINavigationViewController::popToRootViewController(UINAVIGATION_ANIMATION animation) {
    if ( m_viewControllers.size() <= 1) {
      return ;
    }

    while (m_viewControllers.back() != m_viewControllers.front()) {
      m_viewControllers.back()->navigationController = NULL;
      m_viewControllers.pop_back();
    }

    show(m_viewControllers.back(), animation);
}

void UINavigationViewController::show(UIViewController* viewController, UINAVIGATION_ANIMATION animation) {

  if (animation == UINAVIGATION_ANIMATION::NO_ANIMATION) {
    if (m_currentViewController != NULL) {


      // Serial.printf("[UINavigationViewController::show] 01 m_currentViewController: %s - %d (expect: 3)\n", m_currentViewController == NULL ? "NULL" : "NOT-NULL", m_currentViewController->m_viewStatus);

      if (m_currentViewController->m_viewStatus == didAppear)
          m_currentViewController->viewWillDesappear();
      m_currentViewController->view->removeFromSuperView();

      // Serial.printf("[UINavigationViewController::show] 02 m_currentViewController: %s - %d  (expect: 4)\n", m_currentViewController == NULL ? "NULL" : "NOT-NULL", m_currentViewController->m_viewStatus);

      if (m_currentViewController->m_viewStatus == willDesappear)
          m_currentViewController->viewDidDesappear();
    }
    view->addSubview(viewController->view);

    // Serial.printf("[UINavigationViewController::show] 03 viewController: %s - %d  (expect: 1/5)\n", viewController == NULL ? "NULL" : "NOT-NULL", viewController->m_viewStatus);

    if (viewController->m_viewStatus == didLoaded ||
        viewController->m_viewStatus == desappear )
        viewController->viewWillAppear();
    m_currentViewController = viewController;

    // Serial.printf("[UINavigationViewController::show] 04 viewController: %s - %d (expect: 2)\n", viewController == NULL ? "NULL" : "NOT-NULL", viewController->m_viewStatus);

    if (viewController->m_viewStatus == willAppear)
        viewController->viewDidAppear();
  } else {
    std::function< void (bool)> completion = [viewController, this](bool finished) {
      if (this->m_currentViewController != NULL) {

        // Serial.printf("[UINavigationViewController::show] 05 this->m_currentViewController: %s - %d (expect: 3)\n", this->m_currentViewController == NULL ? "NULL" : "NOT-NULL", this->m_currentViewController->m_viewStatus);

        if (this->m_currentViewController->m_viewStatus == didAppear)
            this->m_currentViewController->viewWillDesappear();
        this->m_currentViewController->view->removeFromSuperView();

        // Serial.printf("[UINavigationViewController::show] 06 this->m_currentViewController: %s - %d   (expect: 4)\n", this->m_currentViewController == NULL ? "NULL" : "NOT-NULL", this->m_currentViewController->m_viewStatus);

        if (this->m_currentViewController->m_viewStatus == willDesappear)
            this->m_currentViewController->viewDidDesappear();
      }
      this->m_currentViewController = viewController;

      // Serial.printf("[UINavigationViewController::show] 07 viewController: %s - %d   (expect: 2)\n", viewController == NULL ? "NULL" : "NOT-NULL", viewController->m_viewStatus);

      if (viewController->m_viewStatus == willAppear)
          viewController->viewDidAppear();
    };
    view->addSubview(viewController->view);

    // Serial.printf("[UINavigationViewController::show] 08 viewController: %s - %d   (expect: 1/5)\n", viewController == NULL ? "NULL" : "NOT-NULL", viewController->m_viewStatus);

    if (viewController->m_viewStatus == didLoaded ||
        viewController->m_viewStatus == desappear )
        viewController->viewWillAppear();
    switch (animation) {
      case UINAVIGATION_ANIMATION::ANIME_FROM_RIGHT : {
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
          break;
      }
      case UINAVIGATION_ANIMATION::ANIME_FROM_LEFT : {
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
          break;
      }
      case UINAVIGATION_ANIMATION::ANIME_FROM_BOTTOM : {
          viewController->view->frame.origin.y = this->view->frame.size.height;
          view->animate(0.3,
                        [viewController, this](float progress) {
                          float height = (float)this->view->frame.size.height;
                          viewController->view->frame.origin.y = (int16_t)(height * (1.0f - progress));
                          if (this->m_currentViewController != NULL) {
                            this->m_currentViewController->view->frame.origin.y = (int16_t)(-height * progress);
                          }
                        },
                        completion);
          break;
      }
      case UINAVIGATION_ANIMATION::ANIME_FROM_TOP : {
          viewController->view->frame.origin.y = -this->view->frame.size.height;
          view->animate(0.3,
                        [viewController, this](float progress) {
                          float height = (float)this->view->frame.size.height;
                          viewController->view->frame.origin.y = (int16_t)(-height * (1.0f - progress));
                          if (this->m_currentViewController != NULL) {
                            this->m_currentViewController->view->frame.origin.y = (int16_t)(height * progress);
                          }
                        },
                        completion);
            break;
      }
    }
  }
}
