cmake_minimum_required(VERSION 3.25)
project(CalculatorProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(CalculatorProject
        calculator/main.cpp
        calculator/calculator.cpp
        calculator/calculator.h
)
