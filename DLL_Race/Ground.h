#pragma once
#include "Transport.h"
#include "API.h"
#include <cstring>
#include <iostream>

class RACE_API Ground : public Transport {
protected:
    const char* name_TC;
    int speed;
    double time_before_rest;
    int rest_time;

public:
    Ground(int air, const char* name_TC, int speed, int time_before_rest, int rest_time);

   
};
