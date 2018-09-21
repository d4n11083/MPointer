//
// Created by Josue Chaves on 21/9/18.
//

#include "MPointer.h"

template <class T>
void MPointer<T>::New(T nu1, T nu2) {
    num1 = nu1;
    num2 = nu2;
    std::cout << num1 + num2 << std::endl;
}

