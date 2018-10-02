cmake_minimum_required(VERSION 3.12)
project(MPointer)

set(CMAKE_CXX_STANDARD 14)

add_executable(MPointer main.cpp MPointer.cpp MPointer.h Cliente/JSON/json.hpp Cliente/Cliente.cpp Cliente/Cliente.h DEFINITIONS.h Cliente/JSON/json.hpp MPointerLista/ListaMPointer.cpp MPointerLista/ListaMPointer.h listampointer/QuicksortMPointer.cpp listampointer/QuicksortMPointer.h listampointer/BubbleSortMPointer.cpp listampointer/BubbleSortMPointer.h listampointer/InsertionSortMPointer.cpp listampointer/InsertionSortMPointer.h garbagecollector/MPointerGC.cpp garbagecollector/MPointerGC.h MPointerLista/NodoMPointer.h MPointerLista/NodoMPointer.cpp)
