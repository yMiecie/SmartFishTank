/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    28/09/2017 00:05*/
/* P-Name:  SmartFishTank   */
/****************************/

#include <UIKit.h>
#include "HomeNavigationViewController.h"
#include "MainPagerViewController.h"

HomeNavigationViewController::HomeNavigationViewController(DependenciesServices* dependenciesServices)
: BaseNavigationViewController(dependenciesServices)
{
    MainPagerViewController *vc = new MainPagerViewController(dependenciesServices);
    m_viewControllers.push_back(vc);

    Serial.printf("[HomeNavigationViewController::HomeNavigationViewController] Created");
}

HomeNavigationViewController::~HomeNavigationViewController() {

  delete m_rootViewController;

  delete topLine;

  /*delete m_temperatureLabel;
  delete m_temperatureImage;
  delete m_temperatureImageView;

  delete m_phLabel;
  delete m_phImage;
  delete m_phImageView;*/
}

void HomeNavigationViewController::viewDidLoad() {
  BaseNavigationViewController::viewDidLoad();

  //header->hiden = false;
  footer->hiden = false;

  topLine = new UILine(UIPointZero(), UIPointMake(footer->frame.size.width, 0));
  footer->addSubview(topLine);

  Serial.printf("[HomeNavigationViewController::HomeNavigationViewController] viewDidLoad\n");

  /*UISize size = UISizeMake(Temperature_Icon_Small_width, Temperature_Icon_Small_height);
  m_temperatureImage = new UIImage(size, Temperature_Icon_bits);
  m_temperatureImageView = new UIImageView(m_temperatureImage);
  m_temperatureImageView->frame.origin.x = 2;
  header->addSubview(m_temperatureImageView);

  Serial.printf("[HomeNavigationViewController::HomeNavigationViewController] viewDidLoad 02\n");

  m_temperatureLabel = new UILabel("T:20°C");
  m_temperatureLabel->frame.origin.x = 12;
  m_temperatureLabel->fontData = SansSerif_bold_12;
  header->addSubview(m_temperatureLabel);
    Serial.printf("[HomeNavigationViewController::HomeNavigationViewController] viewDidLoad 03\n");

  size = UISizeMake(CO2_Icon_Small_width, CO2_Icon_Small_height);
  m_phImage = new UIImage(size, CO2_Icon_Small_bits);
  m_phImageView = new UIImageView(m_phImage);
  m_phImageView->frame.origin.x = 68;
  header->addSubview(m_phImageView);
    Serial.printf("[HomeNavigationViewController::HomeNavigationViewController] viewDidLoad 04\n");

  m_phLabel = new UILabel("pH:7.4");
  m_phLabel->frame.origin.x = 82;
  m_phLabel->fontData = SansSerif_bold_12;
  header->addSubview(m_phLabel);
    Serial.printf("[HomeNavigationViewController::HomeNavigationViewController] viewDidLoad 05\n");*/
}
