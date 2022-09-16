#ifndef SERVICE_H
#define SERVICE_H

#include "LightState.h"
#include "View.h"
#pragma once

class Service
{
public:
    Service(View *viewer);
    virtual ~Service();
    void updateState(std::string strState);

private:
    int lightState;
    View *view;
};

#endif