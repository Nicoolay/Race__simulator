#pragma once
#include "Air.h"
#include "API.h"
#include <cstring>
#include <iostream>

class RACE_API Magic_carpet : public Air {
public:
    Magic_carpet();

    double calculateTime(double distance) override;  // �������������� ����� ��� ������� ������� ������ ��� ��������
};
