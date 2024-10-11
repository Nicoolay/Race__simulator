#include "Magic_carpet.h"
#include <iostream>
#include <windows.h>

// Статические значения для верблюда
Magic_carpet::Magic_carpet() : Air(1, "Ковер-самолёт", 10, 0) {  
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
}

double Magic_carpet::calculateTime(double distance) {
    double reductionFactor = 1.0;

    if (distance >= 10000) {
        reductionFactor = 0.95;  // 5% сокращение
    }
    else if (distance >= 5000) {
        reductionFactor = 0.90;  // 10% сокращение
    }
    else if (distance >= 1000) {
        reductionFactor = 0.97;  // 3% сокращение
    }
    else {
        reductionFactor = 1.0;   // Без сокращения
    }

    return (distance * reductionFactor) / speed;
}

