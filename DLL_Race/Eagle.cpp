#include "Eagle.h"
#include <iostream>
#include <windows.h>

// Статические значения для верблюда
Eagle::Eagle() : Air(1, "Орёл", 8, 6) {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
}

double Eagle::calculateTime(double distance) {
    double reductionFactor = 0.94;
    return (distance* reductionFactor) / speed;
      
}