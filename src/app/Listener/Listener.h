#ifndef __LISTENER_H__
#define __LISTENER_H__

#include "Button.h"
#include "Controller.h"
#include "ClockCheck.h"
#include "DHT11.h"
#include "DHT_Data.h"

class Listener
{
private :
    Button *powerButton;
    Button *modeButton;
    Controller *controller;
    ClockCheck *timeClock;
    DHT11 *dht11;

public:
    Listener(Button *button, Button *powerButton, Controller *control, ClockCheck *time, DHT11 *dht11);
    ~Listener();
    void checkEvent();
};

#endif /* __LISTENER_H__ */
