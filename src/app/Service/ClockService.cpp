#include "ClockService.h"

ClockService::ClockService(ClockView *clockview)
{
    curTime = 0;
    clockView = clockview;
}

ClockService::~ClockService()
{

}

void ClockService::updateEvent()
{
    curTime = time(NULL);
    struct tm *timeDate = localtime(&curTime);
    clockView->updateTime(timeDate);
}