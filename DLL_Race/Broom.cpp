#include "Broom.h"
#include <iostream>
#include <windows.h>

// Статические значения для верблюда
Broom::Broom() : Air(1, "Метла", 20, 0) {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
}

double Broom::calculateTime(double distance) {
    double reductionFactor= 1.00;
    int crutch1{};
    if (distance <= 99000) {
        crutch1 = distance / 1000;
        reductionFactor = 1.00 - (crutch1 / static_cast<double>(100));
       
    }
    else 
        reductionFactor = 0.01; // защита для того что бы коэфицент сокращения не был >100%, при расстояниях >100т. км.


    return (distance * reductionFactor) / speed;
}
