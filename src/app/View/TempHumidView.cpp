#include "TempHumidView.h"

TempHumidView::TempHumidView(LCD *lcd, Led *led1, Led *led2, Led *led3, Led *led4, Led *led5)
{
    this->lcd = lcd;
    light1=led1;
    light2=led2;
    light3=led3;
    light4=led4;
    light5=led5;
}

TempHumidView::~TempHumidView()
{

}

void TempHumidView::setTempHumidData(float temp, float humid)
{
    char buff[30];
    sprintf(buff, "%.1fC ", temp);
    lcd->WriteStringXY(0, 10, buff);
    printf("%s\n", buff);
    sprintf(buff, "%.1f%% ", humid);
    lcd->WriteStringXY(1, 10, buff);
    printf("%s\n", buff);
}

void TempHumidView::Warning()
{
    char buff[30];
    sprintf(buff, "StopTooHighTemp!");
    lcd->WriteStringXY(0, 0, buff);
    // sprintf(buff, "Too high temp!!");
    // lcd->WriteStringXY(1, 0, buff);
    Warning_light();
}

void TempHumidView::Warning_light()
{
    static int warning_prevTime = 0;
    std::cout << millis()-warning_prevTime << std::endl;
    int warning_state = 0;
    if(millis()-warning_prevTime >= 5000)
    {
        warning_prevTime = millis();
        warning_state = !warning_state;
    }
    // else if(millis()-warning_prevTime < 6000)
    // {
    //     light1->Off();
    //     light2->Off();
    //     light3->Off();
    //     light4->Off();
    //     light5->Off();
    //     // warning_state = !warning_state;
    // }
        

    if(warning_state)
    {
        light1->On();
        light2->On();
        light3->On();
        light4->On();
        light5->On();
    }
    else
    {
        light1->Off();
        light2->Off();
        light3->Off();
        light4->Off();
        light5->Off();
    }
}