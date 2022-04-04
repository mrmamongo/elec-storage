cmake_minimum_required(VERSION 3.15)
project(Dan LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 20)

add_library(TV sources/TV/TV.cpp sources/TV/TV_factory.h)
target_include_directories(TV PUBLIC sources/TV)
target_include_directories(TV PUBLIC thirdparty/enums)

add_executable(Dan sources/main.cpp )

add_subdirectory(thirdparty/fmt)
target_link_libraries(Dan TV fmt::fmt)
