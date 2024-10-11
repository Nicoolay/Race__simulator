#include "Transport.h"

Transport::Transport() {}

Transport::Transport(const char* name) {
    strncpy_s(this->name_TC, name, sizeof(this->name_TC) - 1);
    this->name_TC[sizeof(this->name_TC) - 1] = '\0';  // Обеспечиваем нуль-терминатор
}


// Геттер для air
int Transport::getAir() const {
    return air;
}

// Геттер для name_TC
const char* Transport::getName() const {
    return name_TC;
}
