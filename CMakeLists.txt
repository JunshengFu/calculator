project(calc)

cmake_minimum_required (VERSION 3.5)

add_definitions(-std=c++0x)

set(sources
    src/main.cpp 
    src/multiplier.cpp 
    src/divider.cpp)

add_executable(calc ${sources})



