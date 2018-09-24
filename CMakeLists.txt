cmake_minimum_required(VERSION 3.12)
project(MPointer)

set(CMAKE_CXX_STANDARD 14)

add_executable(MPointer main.cpp MPointer.cpp MPointer.h Cliente/JSON/json.hpp Cliente/Cliente.cpp Cliente/Cliente.h DEFINITIONS.h Cliente/JSON/json.hpp)
