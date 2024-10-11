#include "Eagle.h"
#include <iostream>
#include <windows.h>

// ����������� �������� ��� ��������
Eagle::Eagle() : Air(1, "���", 8, 6) {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
}

double Eagle::calculateTime(double distance) {
    double reductionFactor = 0.94;
    return (distance* reductionFactor) / speed;
      
}