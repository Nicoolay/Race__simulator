#pragma once
#include "API.h"
#include <cstring>

class RACE_API Transport {
protected:
    int air{};
    char name_TC[20]{};
    int speed{};
    double time_before_rest{};  // for ground transport
    int rest_time{};  // for ground transport
    int distance_reduction_factor{};  // for air transport

public:
    virtual double calculateTime(double distance) = 0;

    Transport();
    Transport(const char* name);

    int getAir() const;
    const char* getName() const;
};
