#include "Camel.h"
#include <iostream>
#include <windows.h>

// Статические значения для верблюда
Camel::Camel() : Ground(0, "Верблюд", 10, 30, 5) { 
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
}

double Camel::calculateTime(double distance) {
    double time = 0.0;
    double remaining_distance = distance;

    for (int i = 1; remaining_distance > 0; i++) {
        double max_distance_before_rest = speed * time_before_rest;
       
        if (remaining_distance <= max_distance_before_rest) {
            // Если оставшаяся дистанция меньше или равна дистанции до отдыха, завершить гонку
            time += remaining_distance / speed;
            remaining_distance = 0;  // Завершение цикла
        }
        else if(i==1) {
            // Если оставшаяся дистанция больше, пройти максимальную дистанцию до отдыха
            remaining_distance -= max_distance_before_rest;
            time += time_before_rest + rest_time;  // Добавляем время движения и время отдыха
        }
        else {
            remaining_distance -= max_distance_before_rest;
            time += time_before_rest + rest_time+3;  // Добавляем время движения и время отдыха
        }
        
    }

    return time;
}
