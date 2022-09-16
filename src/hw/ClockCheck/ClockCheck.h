#ifndef CLOCKCHECK_H
#define CLOCKCHECK_H

#include <time.h>

class ClockCheck
{
public:
    ClockCheck();
    ~ClockCheck();
    bool isUpdate();

private:
    time_t prevSec;
};

#endif