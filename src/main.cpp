#include <iostream>
#include <wiringPi.h>
#include "Button.h"
#include "Led.h"
#include "Listener.h"
#include "Controller.h"
#include "View.h"
#include "LCD.h"
#include "ClockView.h"
#include "ClockService.h"
#include "ClockCheck.h"
#include "I2C.h"
#include "DHT11.h"
#include "DHT_Data.h"
#include "TempHumidService.h"
#include "TempHumidView.h"
#include <time.h>

int main()
{
    std::cout << "Hello World!" << std::endl;
    // time_t timeSec;
    // struct tm *timeDate;

    ClockCheck clockCheck;
    Button modeButton(27);
    Button powerButton(28);
    Led led1(21);
    Led led2(22);
    Led led3(23);
    Led led4(24);
    Led led5(25);
    DHT11 dht(7);
    DHT_Data dhtData;
    LCD lcd(new I2C("/dev/i2c-1", 0x27));

    View view(&led1, &led2, &led3, &led4, &led5, &lcd);
    ClockView clockView(&lcd);
    TempHumidView tempHumidView(&lcd, &led1, &led2, &led3, &led4, &led5);

    Service service(&view);
    ClockService clockService(&clockView);
    TempHumidService tempHumidService(&tempHumidView, &view);
    
    Controller control(&service, &clockService, &tempHumidService);
    Listener listener(&modeButton, &powerButton, &control, &clockCheck, &dht);
    
    while (1)
    {
        // dhtData = dht.readData();
        // if(!dhtData.error)
        // {
        //     std::cout << "humidity : " << dhtData.RH
        //     << "." << dhtData.RHDec
        //     << "%, Temperature : " << dhtData.Temp <<
        //     "." << dhtData.TempDec << "C" << std::endl;
        // }
        listener.checkEvent();
        view.lightView();
        delay(50);
    }

    return 0;
}