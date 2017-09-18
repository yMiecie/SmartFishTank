/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    04/09/2017 11:08*/
/* P-Name:  Smart Fish Tank */
/****************************/

#include "Display/DisplaySSD1306.h"
#include "UI/core/UIScreen.h"
#include "UI/core/UIViewController.h"
#include "UI/core/UILabel.h"
#include "Sensors/Thermometer/ThermometerDS18B20.h"
#include "Sensors/Button/Button.h"

//  OLED display
#define PIN_SDA 21
#define PIN_SCL 22
Display *_display;

//  BUTTON pins
#define PIN_BUTTON_WHITE  14
#define PIN_BUTTON_YELLOW 12
#define PIN_BUTTON_RED    13
Button buttonWhite(PIN_BUTTON_WHITE, BUTTON_TYPE::BUTTON_TYPE_ACTIVE_HIGH);
Button buttonYellow(PIN_BUTTON_YELLOW, BUTTON_TYPE::BUTTON_TYPE_ACTIVE_HIGH);
Button buttonRed(PIN_BUTTON_RED, BUTTON_TYPE::BUTTON_TYPE_ACTIVE_HIGH);

// Thermometer
#define PIN_THERMOMETER  27
ThermometerDS18B20 thermometer(PIN_THERMOMETER);

// UI
UIScreen *_screen;

// Button handler
void onButtonPressed(uint8_t pin) {

  switch (pin) {
    case PIN_BUTTON_YELLOW:
    {
        float temp = thermometer.temperature(1);
        Serial.printf("[ThermometerDS18B20::temperature] Current temperature in water %.2f °C.\n", temp);
        break;
    }
    case PIN_BUTTON_RED:
    {
      float temp = thermometer.temperature(0);
      Serial.printf("[ThermometerDS18B20::temperature] Current temperature in air %.2f °C.\n", temp);
      break;
    }
    default:
    {
      break;
    }
  }

}

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println();

  // Display
  _display = new DisplaySSD1306(PIN_SDA, PIN_SCL);

  // UI
  _screen = new UIScreen(_display);

  UILabel *label = new UILabel("YOLO");

  UIViewController* vc = new UIViewController();
  vc->view->addSubview(label);

  _screen->viewController = vc;

  // button
  buttonWhite.setHandler(&onButtonPressed, BUTTON_STATE::BUTTON_STATE_PRESSED);
  buttonYellow.setHandler(&onButtonPressed, BUTTON_STATE::BUTTON_STATE_PRESSED);
  buttonRed.setHandler(&onButtonPressed, BUTTON_STATE::BUTTON_STATE_PRESSED);
}

void loop() {

  // Update UIScreen
  int remainingTimeBudget = _screen->update();

  if (remainingTimeBudget > 0) {

    // You can do some work here
    // Don't do stuff if you are below your
    // time budget.

    buttonWhite.update();
    buttonYellow.update();
    buttonRed.update();

    /*int reading = digitalRead(PIN_BUTTON_WHITE);     // On lit l'état du bouton | Button state reading
    if (reading != buttonStateWhite) {
      buttonStateWhite = reading;         // enregistre l'état | record the new state

      if (buttonStateWhite == HIGH) {
        Serial.print("ButtonWhite: ON\n");
      } else {
          Serial.print("ButtonWhite: OFF\n");
      }
    }

    reading = digitalRead(PIN_BUTTON_YELLOW);     // On lit l'état du bouton | Button state reading
    if (reading != buttonStateYellow) {
      buttonStateYellow = reading;         // enregistre l'état | record the new state

      if (buttonStateYellow == HIGH) {
        Serial.print("ButtonYellow: ON\n");

        float temp = thermometer.temperature(0);
        Serial.printf("[ThermometerDS18B20::temperature] Current temperature in air %.2f °C.\n", temp);

      } else {
          Serial.print("ButtonYellow: OFF\n");
      }
    }

    reading = digitalRead(PIN_BUTTON_RED);     // On lit l'état du bouton | Button state reading
    if (reading != buttonStateRed) {
      buttonStateRed = reading;         // enregistre l'état | record the new state

      if (buttonStateRed == HIGH) {
        Serial.print("ButtonRed: ON\n");


      } else {
          Serial.print("ButtonRed: OFF\n");
      }
    }*/

    delay(remainingTimeBudget);
  }
}
