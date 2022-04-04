cmake_minimum_required(VERSION 3.15)
project(Dan LANGUAGES CXX C) # Название проекта и опции

set(CMAKE_CXX_STANDARD 20) # Флаги для компилятора

add_library(TV TV/TV.cpp)
target_include_directories(TV PUBLIC TV)
target_include_directories(TV PUBLIC enums)

add_executable(Dan main.cpp) # Объявление исполняемого файла

add_subdirectory(fmt)
target_link_libraries(Dan TV fmt::fmt)
