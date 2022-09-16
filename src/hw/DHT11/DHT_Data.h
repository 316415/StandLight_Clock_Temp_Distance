#ifndef __DHT_Data_H__
#define __DHT_Data_H__

#include "DHT_Data.h"

class DHT_Data
{
public:
    int RH;
    int RHDec;
    int Temp;
    int TempDec;
    int checksum;
    int error;
};

#endif