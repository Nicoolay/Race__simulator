#include <iostream>
#include <string>
#include <windows.h>
#include "API.h"
#include "Transport.h"
#include "Air.h"
#include "transport_factory.h"

void type_of_race(int race_type, double distance) { // для сокращения количества кода, т.к. используется часто
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

// для сокращения количества кода, т.к. используется часто, namespace std перекочевал из прошлой версии, оставил, но в основном коде решил не использовать.
void list_TC(WD_boots& boots, Broom& broom, Camel& camel, Kentavr& kentavr, Eagle& eagle, Fast_Camel& f_camel, Magic_carpet& carpet) { 
    using namespace std; 
    cout << "1. " << boots.getName() << "\n";
    cout << "2. " << broom.getName() << "\n";
    cout << "3. " << camel.getName() << "\n";
    cout << "4. " << kentavr.getName() << "\n";
    cout << "5. " << eagle.getName() << "\n";
    cout << "6. " << f_camel.getName() << "\n";
    cout << "7. " << carpet.getName() << "\n";
    cout << "0. Закончить регистрацию и начать гонку" << endl;
}

bool reg_check(Transport* transport, Transport** transports, int currentCount) { // проверка на регистрацию
    for (int i = 0; i < currentCount; ++i) {  
        if (transports[i] == transport) {  
            return true;  // Объект уже зарегистрирован
        }
    }
    return false;  // Объект не найден
}

void registration_TC(WD_boots& boots, Broom& broom, Camel& camel, Kentavr& kentavr, Eagle& eagle, Fast_Camel& f_camel, Magic_carpet& carpet, int race_type, double distance, Transport** transports, int& currentCount) {
    std::cout << "Выберете транспорт или \"0\" для окончания процесса регистрации: ";
    int choice{};
    std::cin >> choice;
    while (choice!=0) {
       if (currentCount >= 7) {
            std::cout << "Массив заполнен, регистрация завершена." << std::endl;
            break;
        }
  
        switch (choice) {
      
        
        case 1:
            if (race_type == 2) {
                std::cout << "Эта гонка только для воздушного транспорта!" << std::endl;
                }            
            else
                if (reg_check(&boots, transports, currentCount)) {
                    std::cout << boots.getName() << " уже зарегистрирован." << std::endl;
                    break;
                }
                else {
                    transports[currentCount] = &boots;
                    std::cout << boots.getName() << " успешно зарегистрированы!" << std::endl;
                    type_of_race(race_type, distance);
                    list_TC(boots, broom, camel, kentavr, eagle, f_camel, carpet);
                    currentCount++;
                    break;
                }
           
        case 2:
            if (race_type == 1) {
                std::cout << "Эта гонка только для наземного транспорта!" << std::endl;
                break;
            }
            else
                if (reg_check(&broom, transports, currentCount)) {
                    std::cout << broom.getName() << " уже зарегистрирован." << std::endl;
                    break;
                }
                else {
                    transports[currentCount] = &broom;
                    std::cout << broom.getName() << " успешно зарегистрирована!" << std::endl;
                    type_of_race(race_type, distance);
                    list_TC(boots, broom, camel, kentavr, eagle, f_camel, carpet);
                    currentCount++;
                    break;
                }
            
        case 3:
            if (race_type == 2) {
                std::cout << "Эта гонка только для воздушного транспорта!" << std::endl;
                break;
            }
            else
                if (reg_check(&camel, transports, currentCount)) {
                    std::cout << camel.getName() << " уже зарегистрирован." << std::endl;
                    break;
                }
                else {
                    transports[currentCount] = &camel;
                    std::cout << camel.getName() << " успешно зарегистрирован!" << std::endl;
                    type_of_race(race_type, distance);
                    list_TC(boots, broom, camel, kentavr, eagle, f_camel, carpet);
                    currentCount++;
                    break;
                }
            
        case 4:
            if (race_type == 2) {
                std::cout << "Эта гонка только для воздушного транспорта!" << std::endl;
                break;
            }
            else
                if (reg_check(&kentavr, transports, currentCount)) {
                    std::cout << kentavr.getName() << " уже зарегистрирован." << std::endl;
                    break;
                }
                else {
                    transports[currentCount] = &kentavr;
                    std::cout << kentavr.getName() << " успешно зарегистрирован!" << std::endl;
                    type_of_race(race_type, distance);
                    list_TC(boots, broom, camel, kentavr, eagle, f_camel, carpet);
                    currentCount++;
                    break;
                }
           
        case 5:
            if (race_type == 1) {
                std::cout << "Эта гонка только для наземного транспорта!" << std::endl;
                break;
            }
            else
                if (reg_check(&eagle, transports, currentCount)) {
                    std::cout << eagle.getName() << " уже зарегистрирован." << std::endl;
                    break;
                }
                else {
                    transports[currentCount] = &eagle;
                    std::cout << eagle.getName() << " успешно зарегистрирован!" << std::endl;
                    type_of_race(race_type, distance);
                    list_TC(boots, broom, camel, kentavr, eagle, f_camel, carpet);
                    currentCount++;
                    break;
                }
           
        case 6:
            if (race_type == 2) {
                std::cout << "Эта гонка только для воздушного транспорта!" << std::endl;
                break;
            }
            else
                if (reg_check(&f_camel, transports, currentCount)) {
                    std::cout << f_camel.getName() << " уже зарегистрирован." << std::endl;
                    break;
                }
                else {
                    transports[currentCount] = &f_camel;
                    std::cout << f_camel.getName() << " успешно зарегистрирован!" << std::endl;
                    type_of_race(race_type, distance);
                    list_TC(boots, broom, camel, kentavr, eagle, f_camel, carpet);
                    currentCount++;
                    break;
                }
           
        case 7:
            if (race_type == 1) {
                std::cout << "Эта гонка только для наземного транспорта!" << std::endl;
                break;
            }
            if (reg_check(&carpet, transports, currentCount)) {
                std::cout << carpet.getName() << " уже зарегистрирован." << std::endl;
                break;
            }
            else {
                transports[currentCount] = &carpet;
                std::cout << carpet.getName() << " успешно зарегистрирован!" << std::endl;
                type_of_race(race_type, distance);
                list_TC(boots, broom, camel, kentavr, eagle, f_camel, carpet);
                currentCount++;
                break;
            }
            
        default:
            std::cout << "Неверный выбор. Попробуйте снова." << std::endl;
            break;  // Переход к следующему выбору без увеличения счетчика
        }
        
        std::cin >> choice;
    }
    if (currentCount < 2) {
        std::cout << "Нужно зарегистрировать минимум двух участников!" << std::endl;
        registration_TC(boots, broom, camel, kentavr, eagle, f_camel, carpet, race_type, distance, transports, currentCount);
        
    }
}

void bubbleSort(Transport* transports[], int currentCount, double distance) {    // Сортировка по времени
    for (int i = 0; i < currentCount - 1; ++i) {
        for (int j = 0; j < currentCount - i - 1; ++j) {
        
            if (transports[j]->calculateTime(distance) > transports[j + 1]->calculateTime(distance)) {                
                Transport* temp = transports[j];
                transports[j] = transports[j + 1];
                transports[j + 1] = temp;
            }
        }
    }
}



int main(int argc, char* argv[])
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Broom broom;
    Eagle eagle;
    Magic_carpet carpet;
    WD_boots boots;
    Kentavr kentavr;
    Fast_Camel f_camel;
    Camel camel;
    size_t total_transports = 0;
    Transport** transports_all = makeTransports(total_transports);
    int restart{};
    do {
        std::cout << "Добро пожаловать, в гоночный симулятор!" << "\n" << "1. Гонка для наземного транспорта" << "\n"
            << "2. Гонка для воздушного транспорта" << "\n" << "3. Гонка для наземного и воздушного транспорта" << "\n" << "Введите тип гонки:" << std::endl;
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

        list_TC(boots, broom, camel, kentavr, eagle, f_camel, carpet);
        int currentCount = 0;
        size_t selected_transports = 7;
        Transport** transports_race = new Transport * [selected_transports];

        registration_TC(boots, broom, camel, kentavr, eagle, f_camel, carpet, race_type, distance, transports_race, currentCount);
        bubbleSort(transports_race, currentCount, distance);
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



}
