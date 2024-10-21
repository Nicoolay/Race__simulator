#pragma once
#include "API.h"
#include "Transport.h"
#include <cstring>
#include <iostream>

class RACE_API Air : public Transport {
protected:
   /* int air;*/
    const char* name_TC;
    int speed;
    int distance_reduction_factor;
public:
    Air(int air, const char* name_TC, int speed, int distance_reduction_factor);

};
