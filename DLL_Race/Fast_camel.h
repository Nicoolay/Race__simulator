#pragma once
#include "Ground.h"
#include "API.h"
#include <cstring>
#include <iostream>

class RACE_API Fast_Camel : public Ground {
public:
    Fast_Camel();

    double calculateTime(double distance) override;  // Переопределяем метод для расчета времени отдыха для верблюда
};
