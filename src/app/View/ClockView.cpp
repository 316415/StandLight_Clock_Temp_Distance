#include "ClockView.h"

ClockView::ClockView(LCD *lcd)
{
    this->lcd = lcd;
    // timeDate = 0;
}

ClockView::~ClockView()
{
}

void ClockView::updateTime(tm *timeDate)
{
    char buff[30];
    sprintf(buff, "%02d:%02d:%02d", timeDate->tm_hour, timeDate->tm_min, timeDate->tm_sec);
    lcd->WriteStringXY(1, 0, buff);
}