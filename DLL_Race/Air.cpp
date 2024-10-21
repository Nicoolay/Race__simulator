#include "Air.h"



Air::Air(int air, const char* name_TC, int speed, int distance_reduction_factor)
    : Transport(name_TC, air), speed(speed), distance_reduction_factor(distance_reduction_factor) {}
