//
// Created by Josue Chaves on 21/9/18.
//

#ifndef MPOINTER_MPOINTER_H
#define MPOINTER_MPOINTER_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>


template <typename T>
class MPointer {
private:
    T* puntero = nullptr;

public:

    MPointer();
    static MPointer<T> New();

};

template <typename T>
MPointer<T> MPointer<T>::New(){

    std::cout <<"Se ha creado un nuevo puntero..." << std::endl;
}
#endif //MPOINTER_MPOINTER_H
