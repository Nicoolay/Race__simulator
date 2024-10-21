#include <iostream>
#include <string>
#include <windows.h>
#include "transport_factory.h"

void type_of_race(int race_type, double distance) {
    switch (race_type){
        case 1:
            std::cout << "Гонка для наземного транспорта. Расстояние: " << distance << std::endl;
            break;
        case 2:
            std::cout << "Гонка для воздушного транспорта. Расстояние: " << distance << std::endl;
            break;
        case 3:
            std::cout << "Гонка для наземного и воздушного транспорта. Расстояние: " << distance << std::endl;
            break;             
    
    }

}

void list_TC(Transport** transports, size_t total_transports) {
    for (size_t i = 0; i < total_transports; ++i) {
        std::cout << i + 1 << ". " << transports[i]->getName() << std::endl;
    }
    std::cout << "0. Закончить регистрацию и начать гонку" << std::endl;
}

bool reg_check(Transport* transport, Transport** transports_race, int currentCount) { // проверка на регистрацию
    for (int i = 0; i < currentCount; ++i) {
        if (transports_race[i] == transport) {  
            return 1;  // Объект уже зарегистрирован
        }
    }
    return 0;  // Объект не найден
}

void registrated_transports(Transport** transports_race, int& currentCount) {
    std::cout << "Зарегистрированные транспортные средства: ";
    for (int i = 0; i < currentCount; i++) {
        std::cout << transports_race[i]->getName();
        if (i < currentCount - 1) {
            std::cout << ", ";  
        }
    }
    std::cout << std::endl;  
}

bool get_air_check(Transport** transports_all, int race_type, int choice, size_t total_transports) {
    if (choice == 0) {
        return true; // 0 - корректный выбор для завершения регистрации
    }

    // Проверяем, корректен ли выбор транспорта
    if (choice < 1 || choice > total_transports) {
        return false; // Неверный выбор
    }

    // Проверяем, является ли транспорт наземным или воздушным, и соответствует ли это типу гонки
    if (transports_all[choice - 1]->getAir() == 0 && race_type == 1) {
        return true; // Наземный транспорт для наземной гонки
    }
    else if (transports_all[choice - 1]->getAir() == 1 && race_type == 2) {
        return true; // Воздушный транспорт для воздушной гонки
    }
    else if (race_type == 3) {
        return true; // Любой транспорт для смешанной гонки
    }

    return false; // Неправильный вид транспорта для текущего типа гонки
}
void registration_TC(Transport** transports_all, size_t total_transports, Transport** transports_race, int& currentCount, int& race_type, double distance) {
    //for (int i = 0; i < total_transports; i++) {
    //    std::cout << transports_all[i]->getAir() << "\n"; /*проверка для getAir*/
    //}
    int choice = -1;
    std::cout << "Выберите транспорт или \"0\" для окончания регистрации: ";

    while (true) {
        std::cin >> choice;
      
        if (!get_air_check(transports_all, race_type, choice,total_transports)) {
            std::cout << "Попытка зарегистрировать неправильный вид транспорта!" << std::endl;
            continue; // Продолжайте цикл для нового выбора
        }
        // Проверка завершения регистрации
        if (choice == 0) {
            if (currentCount < 2) {
                std::cout << "Нужно зарегистрировать минимум двух участников!" << std::endl;
                continue;  // не выходим, пока не зарегистрируем двух участников
            }
            std::cout << "Регистрация завершена." << std::endl;
            break;
        }

      

        // Проверка корректности выбора (в пределах общего числа транспортов)
        if (choice > static_cast<int>(total_transports) || choice < 0) {
            std::cout << "Неверный выбор. Попробуйте снова." << std::endl;
            continue;
        }

        // Проверка, зарегистрирован ли уже выбранный транспорт
        if (reg_check(transports_all[choice - 1], transports_race, currentCount)) {
            std::cout << "\n";
            std::cout << transports_all[choice - 1]->getName() << " уже зарегистрирован." << std::endl;
            std::cout << "\n";
        }
        else {
            // Проверка переполнения массива
            if (currentCount >= 7) {
                std::cout << "Массив для участников гонки заполнен." << std::endl;
                break;
            }
      

            transports_race[currentCount] = transports_all[choice - 1];
            std::cout << transports_all[choice - 1]->getName() << " успешно зарегистрирован!" << std::endl;
            std::cout << "\n";
            currentCount++; 
            type_of_race(race_type, distance);            
            std::cout << "\n";
            registrated_transports(transports_race, currentCount);
            std::cout << "\n";
            list_TC(transports_all, total_transports);
            std::cout << "\n";                               
        }
    }
}



void quickSort(Transport** transports_race, int left, int right, double distance) {
    int i = left;
    int j = right;
    double pivot = transports_race[(left + right) / 2]->calculateTime(distance); // Опорный элемент

    while (i <= j) {
        // Находим элементы, которые нужно обменять
        while (transports_race[i]->calculateTime(distance) < pivot) {
            i++;
        }
        while (transports_race[j]->calculateTime(distance) > pivot) {
            j--;
        }
        if (i <= j) {
            // Меняем местами элементы
            Transport* temp = transports_race[i];
            transports_race[i] = transports_race[j];
            transports_race[j] = temp;
            i++;
            j--;
        }
    }
    if (left < j) {
        quickSort(transports_race, left, j, distance);
    }
    if (i < right) {
        quickSort(transports_race, i, right, distance);
    }
}

int main(int argc, char* argv[])
{
   
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);  
    size_t total_transports = 0;
    Transport** transports_all = makeTransports(total_transports);
    int restart{};

    do {
        std::cout << "Добро пожаловать, в гоночный симулятор!" << "\n"
            << "1. Гонка для наземного транспорта" << "\n"
            << "2. Гонка для воздушного транспорта" << "\n" 
            << "3. Гонка для наземного и воздушного транспорта" << "\n"
            << "Введите тип гонки:" << std::endl;
        int race_type{};
        while (race_type != 1 && race_type != 2 && race_type != 3) {
            std::cin >> race_type;
            if (race_type != 1 && race_type != 2 && race_type != 3) {
                std::cout << "Нужно указать значение от 1 до 3х. Попробуйте снова." << std::endl;
            }
        }
        std::cout << "Укажите длинну дистанции(должна быть положительна): " << std::endl;
        double distance{};
        while (distance <= 0.0) {
            std::cin >> distance;
            if (distance <= 0.0) {
                std::cout << "Значение должно быть положительным. Попробуйте снова" << std::endl;
            }
        }
        std::cout << "Должно быть зарегистрировано хотя бы 2 транспортных средства:" << "\n" << "1. Зарегистрировать транспорт" << "\n" << "Выберете действие:" << std::endl;
        int next_1{};
        while (next_1 != 1) {
            std::cin >> next_1;
            if (next_1 != 1) {
                std::cout << "Выберете действие из списка. Попробуйте снова." << std::endl;
            }
        }
        type_of_race(race_type, distance);

        list_TC(transports_all, total_transports);
        int currentCount = 0;
        size_t selected_transports = 7;
        Transport** transports_race = new Transport * [selected_transports];
        registration_TC(transports_all, total_transports, transports_race, currentCount, race_type, distance);      
        quickSort(transports_race, 0, currentCount - 1, distance);
        std::cout << "Результаты гонки: " << std::endl;
        int count_1 = 1;
        for (int i = 0; i < currentCount; ++i) {            
            std::cout << count_1 << ". " << transports_race[i]->getName() << " время: " << transports_race[i]->calculateTime(distance) << std::endl;
            count_1++;
        }

        std::cout <<"\n" << "1. Провести ещё одну гонку" << "\n" << "2. Выйти" << "\n" << "Выберете действие: " << std::endl;
        std::cin >> restart;
        delete[] transports_race;
    }

    while (restart != 2);
    for (size_t i = 0; i < total_transports; ++i) {
        delete transports_all[i];
    }
    delete[] transports_all;
    return 0;
}
