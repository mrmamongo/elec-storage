cmake_minimum_required(VERSION 3.15)
project(Dan LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 20)

add_library(TV
        sources/storage/TV.cpp sources/storage/TV_factory.h sources/storage/TV_factory.h
        sources/storage/Fridge.cpp sources/storage/Fridge.h sources/storage/Fridge_factory.h
        sources/storage/i_elec_factory.h sources/storage/i_electronic.h sources/storage/elec_storage.h
        )
target_include_directories(TV PUBLIC sources/TV)
target_include_directories(TV PUBLIC thirdparty/enums)

add_executable(Dan sources/main.cpp )

add_subdirectory(thirdparty/fmt)
target_link_libraries(Dan TV fmt::fmt)
