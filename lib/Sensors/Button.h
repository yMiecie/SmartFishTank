/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    17/09/2017 20:16*/
/* P-Name:  Sensors         */
/****************************/

#include <Arduino.h>
#include <vector>

#ifndef BUTTON_H
#define BUTTON_H

enum class BUTTON_TYPE {
  BUTTON_TYPE_ACTIVE_LOW = 0,
  BUTTON_TYPE_ACTIVE_HIGH = 1,
};

enum class BUTTON_STATE {
  BUTTON_STATE_RELEASED = 0,
  BUTTON_STATE_PRESSED
};

typedef void(*ButtonHandler)(const uint8_t pin); // The parameter is the pin of the button

class Button{
public:
  Button(uint8_t pin, BUTTON_TYPE type);
  ~Button();

  void setHandler(const ButtonHandler handler, const BUTTON_STATE state);
  void update();

private:
  uint8_t         m_pin;
  int             m_currentState;
  BUTTON_TYPE     m_type;
  std::vector<ButtonHandler>  m_handlers;
};

#endif
