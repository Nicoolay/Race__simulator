#include "Air.h"

// Реализация конструктора с инициализацией переменных
Air::Air(int air, const char* name_TC, int speed, int distance_reduction_factor)
    : Transport(name_TC), air(air), name_TC(name_TC), speed(speed), distance_reduction_factor(distance_reduction_factor) {}

