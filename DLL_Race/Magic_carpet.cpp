#include "Magic_carpet.h"
#include <iostream>
#include <windows.h>

// ����������� �������� ��� ��������
Magic_carpet::Magic_carpet() : Air(1, "�����-������", 10, 0) {  
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
}

double Magic_carpet::calculateTime(double distance) {
    double reductionFactor = 1.0;

    if (distance >= 10000) {
        reductionFactor = 0.95;  // 5% ����������
    }
    else if (distance >= 5000) {
        reductionFactor = 0.90;  // 10% ����������
    }
    else if (distance >= 1000) {
        reductionFactor = 0.97;  // 3% ����������
    }
    else {
        reductionFactor = 1.0;   // ��� ����������
    }

    return (distance * reductionFactor) / speed;
}

