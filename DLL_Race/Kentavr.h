#pragma once
#include "Ground.h"
#include "API.h"
#include <cstring>
#include <iostream>

class RACE_API Kentavr : public Ground {
public:
    Kentavr();

    double calculateTime(double distance) override;  // Переопределяем метод для расчета времени отдыха для верблюда
};
