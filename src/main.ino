/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    04/09/2017 11:08*/
/* P-Name:  Smart Fish Tank */
/****************************/

#include <sstream>
#include "images.h"
#include <DisplaySSD1306.h>
#include <UIKit.h>
#include <Sensors.h>

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
      _nc->popToRootViewController(true);
      break;
    }
    case PIN_BUTTON_YELLOW:
    {
        _nc->popViewController(true);
        //float temp = thermometer.temperature(1);
        //Serial.printf("[ThermometerDS18B20::temperature] Current temperature in water %.2f °C.\n", temp);
        break;
    }
    case PIN_BUTTON_RED:
    {

        UIViewController* vc = new UIViewController();

        int size = _nc->viewControllers.size();
        std::stringstream ss;
        ss << "ViewController " << size;
        String text = String(ss.str().c_str());
        UILabel *label01 = new UILabel(text);
        label01->frame.origin.y = 15;
        vc->view->addSubview(label01);

        if (size == 1) {
          UILabel *label02 = new UILabel("Air temperature: 18°C");
          label02->frame.origin.x = 20;
          label02->frame.origin.y = 30;
          vc->view->addSubview(label02);

          UISize size = UISizeMake(Temperature_Icon_Small_width, Temperature_Icon_Small_height);
          UIImage *image = new UIImage(size, Temperature_Icon_bits);
          UIImageView *imageView = new UIImageView(image);
          imageView->frame.origin.y = 30;
          vc->view->addSubview(imageView);

        } else if (size == 2) {
          UILabel *label02 = new UILabel("Water temperature: 16°C");
          label02->frame.origin.x = 20;
          label02->frame.origin.y = 30;
          vc->view->addSubview(label02);

          UISize size = UISizeMake(Temperature_Icon_Small_width, Temperature_Icon_Small_height);
          UIImage *image = new UIImage(size, Temperature_Icon_bits);
          UIImageView *imageView = new UIImageView(image);
          imageView->frame.origin.y = 30;
          vc->view->addSubview(imageView);

        } else if (size == 3) {
          UILabel *label02 = new UILabel("pH: ???");
          label02->frame.origin.x = 20;
          label02->frame.origin.y = 30;
          vc->view->addSubview(label02);

          UISize size = UISizeMake(CO2_Icon_Small_width, CO2_Icon_Small_height);
          UIImage *image = new UIImage(size, CO2_Icon_Small_bits);
          UIImageView *imageView = new UIImageView(image);
          imageView->frame.origin.y = 30;
          vc->view->addSubview(imageView);

        }

        _nc->pushViewController(vc, true);
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

  UILabel *navLabel = new UILabel("Main NavigationController");
  UIViewController *vc = new UIViewController();
  UILabel *label01 = new UILabel("ViewController 0");
  label01->frame.origin.y = 15;
  vc->view->addSubview(label01);
  UILabel *label02 = new UILabel("Hello World !");
  label02->frame.origin.y = 30;
  vc->view->addSubview(label02);
  _nc = new UINavigationViewController(vc);
  _nc->view->frame.size = _screen->size();
  _nc->view->addSubview(navLabel);

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
