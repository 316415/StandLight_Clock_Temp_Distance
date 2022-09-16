#ifndef CLOCKVIEW_H
#define CLOCKVIEW_H

#pragma once
#include <time.h>
#include "LCD.h"

class ClockView
{
private:
    struct tm timeDate;
    LCD *lcd;

public:
    ClockView(LCD *lcd);
    ~ClockView();
    void updateTime(tm *timeDate);
};

#endif