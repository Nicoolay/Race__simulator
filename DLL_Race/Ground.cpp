#include "Ground.h"

Ground::Ground(int air, const char* name_TC, int speed, int time_before_rest, int rest_time)
    : Transport(name_TC), air(air), name_TC(name_TC), speed(speed), time_before_rest(time_before_rest), rest_time(rest_time){}

//double Ground::calculateTime(double distance) {
//    // ������ ��� ������� ������� ������ (�� ���������)
//    stop_count++;
//    return rest_time;  // ��� �������� ������ ������ ���������� rest_time
//}
