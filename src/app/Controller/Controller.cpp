#include "Controller.h"

Controller::Controller(Service *serv, ClockService *clockServ, TempHumidService *tempHumidService)
{
    service = serv;
    clockService = clockServ;
    lightState = LIGHT_OFF;
    this->tempHumidService = tempHumidService;
}

Controller::~Controller()
{
}

void Controller::updateEvent(std::string strBtn)
{
    if (strBtn == "modeButton")
    {
        service->updateState("modeButton");
    }

    if (strBtn == "powerButton")
    {
        service->updateState("powerButton");
    }

    if (strBtn == "clockUpdate")
    {
        clockService->updateEvent();
    }

}

void Controller::updateTempHumid(DHT_Data dhtData)
{
    tempHumidService->updateEvent(dhtData);
}