#pragma once
#include "Ground.h"
#include "API.h"
#include <cstring>
#include <iostream>

class RACE_API WD_boots : public Ground {
public:
    WD_boots();

    double calculateTime(double distance) override;  // Переопределяем метод для расчета времени отдыха
};
