//
// Created by Josue Chaves on 21/9/18.
//

#ifndef MPOINTER_MPOINTER_H
#define MPOINTER_MPOINTER_H

#include <iostream>;


template <typename T>
class MPointer {

private:
    T num1;
    T num2;

public:

    MPointer() { num1 = 0; num2 = 0; }
    void New(T nu1, T nu2 );

};


#endif //MPOINTER_MPOINTER_H
