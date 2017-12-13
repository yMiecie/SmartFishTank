/****************************/
/* Author:  MIECIELICA YANN */
/* Date:    09/12/2017 00:05*/
/* P-Name:  SmartFishTank   */
/****************************/

#include <UIKit.h>
#include "HomeViewController.h"

HomeViewController::HomeViewController(DependenciesServices* dependenciesServices)
: BaseViewController(dependenciesServices)
{
}

HomeViewController::~HomeViewController() {

    clearTimer();

    delete m_temperatureLabel;
    delete m_temperatureImage;
    delete m_temperatureImageView;

    delete m_phLabel;
    delete m_phImage;
    delete m_phImageView;

    delete m_heaterImage;
    delete m_heaterImageView;
    delete m_heaterStatusLabel;

    delete m_fanImage;
    delete m_fanImageView;
    delete m_fanStatusLabel;

    delete m_valveImage;
    delete m_valveImageView;
    delete m_valveStatusLabel;

    delete m_pumpImage;
    delete m_pumpImageView;
    delete m_pumpStatusLabel;
}

void HomeViewController::viewDidLoad() {
    BaseViewController::viewDidLoad();

    /*
    * Header
    */
    // Temperature
    UISize size = UISizeMake(Temperature_Icon_Small_width, Temperature_Icon_Small_height);
    m_temperatureImage = new UIImage(size, Temperature_Icon_bits);
    m_temperatureImageView = new UIImageView(m_temperatureImage);
    m_temperatureImageView->frame.origin.x = 2;
    view->addSubview(m_temperatureImageView);

    m_temperatureLabel = new UILabel("T:20°C");
    m_temperatureLabel->frame.origin.x = 12;
    m_temperatureLabel->fontData = SansSerif_bold_12;
    view->addSubview(m_temperatureLabel);

    // PH
    size = UISizeMake(CO2_Icon_Small_width, CO2_Icon_Small_height);
    m_phImage = new UIImage(size, CO2_Icon_Small_bits);
    m_phImageView = new UIImageView(m_phImage);
    m_phImageView->frame.origin.x = 68;
    view->addSubview(m_phImageView);

    m_phLabel = new UILabel("pH:7.4");
    m_phLabel->frame.origin.x = 82;
    m_phLabel->fontData = SansSerif_bold_12;
    view->addSubview(m_phLabel);

    /*
    * Body
    */
    // Heater
    size = UISizeMake(SmartFish_heater_width, SmartFish_heater_height);
    m_heaterImage = new UIImage(size, SmartFish_heater_bits);
    m_heaterImageView = new UIImageView(m_heaterImage);
    m_heaterImageView->frame.origin.x = 7;
    m_heaterImageView->frame.origin.y = 22;
    view->addSubview(m_heaterImageView);

    m_heaterStatusLabel = new UILabel(": On");
    m_heaterStatusLabel->frame.origin.x = 21;
    m_heaterStatusLabel->frame.origin.y = 22;
    m_heaterStatusLabel->fontData = SansSerif_bold_10;
    view->addSubview(m_heaterStatusLabel);


    // Fan
    size = UISizeMake(SmartFish_fan_width, SmartFish_fan_height);
    m_fanImage = new UIImage(size, SmartFish_fan_bits);
    m_fanImageView = new UIImageView(m_fanImage);
    m_fanImageView->frame.origin.x = 7;
    m_fanImageView->frame.origin.y = 38;
    view->addSubview(m_fanImageView);

    m_fanStatusLabel = new UILabel(": On");
    m_fanStatusLabel->frame.origin.x = 21;
    m_fanStatusLabel->frame.origin.y = 38;
    m_fanStatusLabel->fontData = SansSerif_bold_10;
    view->addSubview(m_fanStatusLabel);

    // Valve
    size = UISizeMake(SmartFish_valve_width, SmartFish_valve_height);
    m_valveImage = new UIImage(size, SmartFish_valve_bits);
    m_valveImageView = new UIImageView(m_valveImage);
    m_valveImageView->frame.origin.x = 73;
    m_valveImageView->frame.origin.y = 22;
    view->addSubview(m_valveImageView);

    m_valveStatusLabel = new UILabel(": Off");
    m_valveStatusLabel->frame.origin.x = 87;
    m_valveStatusLabel->frame.origin.y = 22;
    m_valveStatusLabel->fontData = SansSerif_bold_10;
    view->addSubview(m_valveStatusLabel);

    // Pump
    size = UISizeMake(SmartFish_pump_width, SmartFish_pump_height);
    m_pumpImage = new UIImage(size, SmartFish_pump_bits);
    m_pumpImageView = new UIImageView(m_pumpImage);
    m_pumpImageView->frame.origin.x = 73;
    m_pumpImageView->frame.origin.y = 38;
    view->addSubview(m_pumpImageView);

    m_pumpStatusLabel = new UILabel(": On");
    m_pumpStatusLabel->frame.origin.x = 87;
    m_pumpStatusLabel->frame.origin.y = 38;
    m_pumpStatusLabel->fontData = SansSerif_bold_10;
    view->addSubview(m_pumpStatusLabel);
}

void HomeViewController::viewDidAppear() {
    BaseViewController::viewDidAppear();

    std::function<void (Timer *)> handler = [this](Timer *timer) {
        this->navigationController->popViewController(true);
    };

    clearTimer();
    m_timer = new Timer(9000, handler, false);
    m_$->timerController()->add(m_timer);
}

void HomeViewController::viewDidUpdate() {
    BaseViewController::viewDidUpdate();


}

void HomeViewController::clearTimer() {
    if (m_timer != NULL) {
        m_$->timerController()->remove(m_timer->id);
        delete m_timer;
        m_timer = NULL;
    }
}
