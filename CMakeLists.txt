cmake_minimum_required(VERSION 3.20.0 FATAL_ERROR)

set(PROJECT_NAME ASCISNAKE)
project(${PROJECT_NAME})

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/GameOBJ/Setup.cpp
    src/GameOBJ/Setup.hpp
)

