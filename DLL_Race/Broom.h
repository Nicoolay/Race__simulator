#pragma once
#include "API.h"
#include "Air.h"
#include <cstring>
#include <iostream>

class RACE_API Broom : public Air {
public:
    Broom();

    double calculateTime(double distance) override;  // Переопределяем метод для расчета времени отдыха для верблюда
};
