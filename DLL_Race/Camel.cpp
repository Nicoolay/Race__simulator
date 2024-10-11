#include "Camel.h"
#include <iostream>
#include <windows.h>

// ����������� �������� ��� ��������
Camel::Camel() : Ground(0, "�������", 10, 30, 5) { 
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
}

double Camel::calculateTime(double distance) {
    double time = 0.0;
    double remaining_distance = distance;

    for (int i = 1; remaining_distance > 0; i++) {
        double max_distance_before_rest = speed * time_before_rest;
       
        if (remaining_distance <= max_distance_before_rest) {
            // ���� ���������� ��������� ������ ��� ����� ��������� �� ������, ��������� �����
            time += remaining_distance / speed;
            remaining_distance = 0;  // ���������� �����
        }
        else if(i==1) {
            // ���� ���������� ��������� ������, ������ ������������ ��������� �� ������
            remaining_distance -= max_distance_before_rest;
            time += time_before_rest + rest_time;  // ��������� ����� �������� � ����� ������
        }
        else {
            remaining_distance -= max_distance_before_rest;
            time += time_before_rest + rest_time+3;  // ��������� ����� �������� � ����� ������
        }
        
    }

    return time;
}
