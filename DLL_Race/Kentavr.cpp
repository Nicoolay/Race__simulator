#include "Kentavr.h"
#include <iostream>
#include <windows.h>

// Статические значения для верблюда
Kentavr::Kentavr() : Ground(0, "Кентавр", 15, 8, 2) {  // Здесь мы задаем фиксированные значения для air, name_TC, speed и time_before_rest
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
}

double Kentavr::calculateTime(double distance) { 
   
    double time= 0.0;
    double remaining_distance = distance;

    for (int i = 1;  remaining_distance > 0; i++) {
        double max_distance_before_rest = speed * time_before_rest;
        if (remaining_distance <= max_distance_before_rest) {
            // Если оставшаяся дистанция меньше или равна дистанции до отдыха, завершить гонку
            time += remaining_distance / speed;
            remaining_distance = 0;  // Завершение цикла
        }
        else {
            // Если оставшаяся дистанция больше, пройти максимальную дистанцию до отдыха
            remaining_distance -= max_distance_before_rest;
            time += time_before_rest + rest_time;  // Добавляем время движения и время отдыха
        }

  }
   
    return time;
}
