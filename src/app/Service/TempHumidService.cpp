#include "TempHumidService.h"

TempHumidService::TempHumidService(TempHumidView *tempHumidView, View *view)
{
    this->tempHumidView = tempHumidView;
    viewer = view;
}

TempHumidService::~TempHumidService()
{

}

void TempHumidService::updateEvent(DHT_Data dhtData)
{
    float temp, humid;
    temp = (float)dhtData.Temp + (float)(dhtData.TempDec/10.0);
    humid = (float)dhtData.RH + (float)(dhtData.RHDec/10.0);
    
    SafetyCheck(temp, humid);
}

void TempHumidService::SafetyCheck(float temp, float humid)
{
    if(temp >= 27)
    {
        tempHumidView->Warning();
        viewer->setState(WARNING);
    }
    else
    {
        tempHumidView->setTempHumidData(temp, humid);
    }
}