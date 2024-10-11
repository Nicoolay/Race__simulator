#pragma once
#include "API.h"
#include "Air.h"
#include <cstring>
#include <iostream>

class RACE_API Eagle : public Air {
public:
    Eagle();

    double calculateTime(double distance) override;  
};
