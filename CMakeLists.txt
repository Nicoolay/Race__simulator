cmake_minimum_required(VERSION 3.22.0)
project(Race_simulator)

# ќпредел€ем компил€цию как дл€ DLL
add_compile_definitions(API_EXPORTS)

# —оздаем библиотеку
add_library(Race_library SHARED 
    "DLL_Race/API.h"
    "DLL_Race/Transport.cpp" "DLL_Race/Transport.h" 
    "DLL_Race/Air.cpp" "DLL_Race/Air.h" 
    "DLL_Race/Ground.cpp" "DLL_Race/Ground.h"     
    "DLL_Race/Broom.cpp" "DLL_Race/Broom.h" 
    "DLL_Race/Eagle.cpp" "DLL_Race/Eagle.h" 
    "DLL_Race/Magic_carpet.cpp" "DLL_Race/Magic_carpet.h"
    "DLL_Race/4wd_boots.cpp" "DLL_Race/4wd_boots.h" 
    "DLL_Race/Kentavr.cpp" "DLL_Race/Kentavr.h" 
    "DLL_Race/Camel.cpp" "DLL_Race/Camel.h" 
    "DLL_Race/Fast_camel.cpp" "DLL_Race/Fast_camel.h"
)

# ”казываем путь к заголовочным файлам дл€ библиотеки
target_include_directories(Race_library PRIVATE "${CMAKE_SOURCE_DIR}/DLL_Race")

# —оздаем исполн€емый файл
add_executable(Race_simulator "Race_client/Race_client.cpp")

# ”казываем путь к заголовочным файлам дл€ клиента
target_include_directories(Race_simulator PRIVATE "${CMAKE_SOURCE_DIR}/DLL_Race")

# Ћинкуем клиент с библиотекой
target_link_libraries(Race_simulator Race_library)
