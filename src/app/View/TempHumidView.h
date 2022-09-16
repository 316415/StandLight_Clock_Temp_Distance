#ifndef TEMPHUMIDVIEW_H
#define TEMPHUMIDVIEW_H

#pragma once
#include "LCD.h"
#include "Led.h"
#include <wiringPi.h>

class TempHumidView
{
public:
    TempHumidView(LCD *lcd, Led *led1, Led *led2, Led *led3, Led *led4, Led *led5);
    ~TempHumidView();
    void setTempHumidData(float temp, float humid);
    void Warning();
    void Warning_light();

private:
    LCD *lcd;
    Led *light1;
    Led *light2;
    Led *light3;
    Led *light4;
    Led *light5;
};

#endif