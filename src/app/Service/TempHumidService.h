#ifndef TEMPHUMIDSERVICE_H
#define TEMPHUMIDSERVICE_H

#pragma once
#include "DHT_Data.h"
#include "TempHumidView.h"
#include "View.h"
#include "LightState.h"

class TempHumidService
{
public:
    TempHumidService(TempHumidView *tempHumidView, View *view);
    virtual ~TempHumidService();
    void updateEvent(DHT_Data dhtData);
    void SafetyCheck(float temp, float humid);

private:
    TempHumidView *tempHumidView;
    View *viewer;
};

#endif