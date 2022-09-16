#ifndef CLOCKSERVICE_H
#define CLOCKSERVICE_H

#include <time.h>
#include "ClockView.h"

#pragma once

class ClockService
{
public:
    ClockService(ClockView *clockview);
    virtual ~ClockService();
    void updateEvent();

private:
    time_t curTime;
    ClockView *clockView; //clockView에게 메세지를 전달할 게 필요함
};

#endif