/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    04/09/2017 11:08*/
/* P-Name:  Smart Fish Tank */
/****************************/

#include <sstream>
#include "Display/DisplaySSD1306.h"
#include "UI/core/UIScreen.h"
#include "UI/core/UINavigationViewController.h"
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
UIScreen                    *_screen;
UINavigationViewController  *_nc;

#define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

// Button handler
void onButtonPressed(uint8_t pin) {

  switch (pin) {
    case PIN_BUTTON_WHITE:
    {
      _nc->popToRootViewController(false);
      break;
    }
    case PIN_BUTTON_YELLOW:
    {
        _nc->popViewController(false);
        //float temp = thermometer.temperature(1);
        //Serial.printf("[ThermometerDS18B20::temperature] Current temperature in water %.2f °C.\n", temp);
        break;
    }
    case PIN_BUTTON_RED:
    {
        std::stringstream ss;
        ss << "YOLO " << _nc->viewControllers.size();
        String text = String(ss.str().c_str());
        UILabel *label = new UILabel(text);
        UIViewController* vc = new UIViewController();
        vc->view->addSubview(label);
        _nc->pushViewController(vc, false);
      //float temp = thermometer.temperature(0);
      //Serial.printf("[ThermometerDS18B20::temperature] Current temperature in air %.2f °C.\n", temp);
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

  UILabel *label = new UILabel("YOLO 0");
  UIViewController *vc = new UIViewController();
  vc->view->addSubview(label);
  _nc = new UINavigationViewController(vc);

  _screen->viewController = _nc;

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

    delay(remainingTimeBudget);
  }
}
