/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    04/09/2017 11:08*/
/* P-Name:  Smart Fish Tank */
/****************************/

#include "Display/DisplaySSD1306.h"
#include "UI/core/UIScreen.h"
#include "UI/core/UIViewController.h"
#include "UI/core/UILabel.h"

//  OLED display
#define PIN_SDA 21
#define PIN_SCL 22
Display *_display;

// UI
UIScreen *_screen;

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
}

int incomingByte = 0;

void loop() {
  _screen->update();

  // send data only when you receive data:
  if (Serial.available() > 0) {
          // read the incoming byte:
          incomingByte = Serial.read();

          // say what you got:
          Serial.print("I received: ");
          Serial.printf("%c\n", incomingByte);
  }
}

/*#include <Wire.h>  // Only needed for Arduino 1.6.5 and earlier
#include "SSD1306.h" // alias for `#include "SSD1306Wire.h"`
#include "OLEDDisplayUi.h" // Include the UI lib

//  OLED display
// 21 -> SDA
// 22 -> SCL

// Initialize the OLED display using Wire library
SSD1306  display(0x3c, 21, 22);

// Include custom images
#include "images.h"

#define DEMO_DURATION 3000
typedef void (*Demo)(void);

int demoMode = 0;
int counter = 1;

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println();


  // Initialising the UI will init the display too.
  display.init();

  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);

}

void drawHeaderDemo() {
    // see http://blog.squix.org/2015/05/esp8266-nodemcu-how-to-create-xbm.html
    // on how to create xbm files
    display.drawXbm(0, 0, CO2_Icon_Small_width, CO2_Icon_Small_height, CO2_Icon_Small_bits);
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.drawString(14,0, "7.4pH");

    display.drawXbm(45, 0, Temperature_Icon_Small_width, Temperature_Icon_Small_height, Temperature_Icon_bits);
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.drawString(55,0, "28°C");

    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.drawString(85,0, "15:47");

    display.drawXbm(114, 0, Wifi_Icon_Small_width, Wifi_Icon_Small_height, Wifi_Icon_bits);
}

Demo demos[] = {drawHeaderDemo};
int demoLength = (sizeof(demos) / sizeof(Demo));
long timeSinceLastModeSwitch = 0;

void loop() {
  // clear the display
  display.clear();
  // draw the current demo method
  demos[demoMode]();

  display.setTextAlignment(TEXT_ALIGN_RIGHT);
  display.drawString(10, 128, String(millis()));
  // write the buffer to the display
  display.display();

  if (millis() - timeSinceLastModeSwitch > DEMO_DURATION) {
    demoMode = (demoMode + 1)  % demoLength;
    timeSinceLastModeSwitch = millis();
  }
  counter++;
  delay(10);
}
*/
