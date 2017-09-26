/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    17/09/2017 20:16*/
/* P-Name:  Sensors         */
/****************************/

#include "Button.h"

void defaultButtonHandler(uint8_t pin) {}

Button::Button(uint8_t pin, BUTTON_TYPE type)
:m_pin(pin), m_type(type), m_currentState(type == BUTTON_TYPE::BUTTON_TYPE_ACTIVE_HIGH ? LOW : HIGH) {

    m_handlers.push_back(&defaultButtonHandler);
    m_handlers.push_back(&defaultButtonHandler);
}

Button::~Button() {
}

void Button::setHandler(ButtonHandler handler, const BUTTON_STATE state) {
  m_handlers[(int)state] = handler;
}

void Button::update() {

  int reading = digitalRead(m_pin);     // On lit l'état du bouton | Button state reading
  if (reading != m_currentState) {

    int pressed = (m_type == BUTTON_TYPE::BUTTON_TYPE_ACTIVE_HIGH ? HIGH : LOW);
    ButtonHandler handler;
    m_currentState = reading;         // enregistre l'état | record the new state

    if (m_currentState == pressed) {
       handler = m_handlers[(int)BUTTON_STATE::BUTTON_STATE_PRESSED];
    } else {
       handler = m_handlers[(int)BUTTON_STATE::BUTTON_STATE_RELEASED];
    }

    handler(m_pin);
  }
}
