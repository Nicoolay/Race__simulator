#include "Fast_Camel.h"
#include <iostream>
#include <windows.h>

// ����������� �������� ��� ��������
Fast_Camel::Fast_Camel() : Ground(0, "�������-���������", 40, 10, 5) {  // ����� �� ������ ������������� �������� ��� air, name_TC, speed � time_before_rest
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
}

double Fast_Camel::calculateTime(double distance) {
    double time = 0.0;
    double remaining_distance = distance;

    for (int i = 1; remaining_distance > 0; i++) {
        double max_distance_before_rest = speed * time_before_rest;

        if (remaining_distance <= max_distance_before_rest) {
            // ���� ���������� ��������� ������ ��� ����� ��������� �� ������, ��������� �����
            time += remaining_distance / speed;
            remaining_distance = 0;  // ���������� �����
        }
        else if (i == 1) {
            // ���� ���������� ��������� ������, ������ ������������ ��������� �� ������
            remaining_distance -= max_distance_before_rest;
            time += time_before_rest + rest_time;  // ��������� ����� �������� � ����� ������
        }
        else if (i == 2) {
            remaining_distance -= max_distance_before_rest;
            time += time_before_rest + rest_time+1.5;  
        }
        else if(i>2)  {
            remaining_distance -= max_distance_before_rest;
            time += time_before_rest + rest_time + 3;  // ��������� ����� �������� � ����� ������
        }

    }

    return time;
}
