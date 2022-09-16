#include "Listener.h"
#include <wiringPi.h>

Listener::Listener(Button *button, Button *powerButton, Controller *control, ClockCheck *time, DHT11 *dht11)
{
    modeButton = button;
    this->powerButton = powerButton;
    controller = control;
    timeClock = time;
    this->dht11 = dht11;
}

Listener::~Listener()
{
}

void Listener::checkEvent()
{
    if (modeButton->getState() == RELEASE_ACTIVE)
    {
        controller->updateEvent("modeButton");
    }

    if (powerButton->getState() == RELEASE_ACTIVE)
    {
        controller->updateEvent("powerButton");
    }

    if (timeClock->isUpdate())
    {
        controller->updateEvent("clockUpdate");
    }

    static unsigned int prevTempHumidTime = 0;
    if(millis() - prevTempHumidTime > 2000)
    {
        prevTempHumidTime = millis();
        DHT_Data dhtData = dht11->readData();
        if(dhtData.error == 0)
        {
            controller->updateTempHumid(dhtData);
        }
    }
    
    
}