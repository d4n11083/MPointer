//
// Created by Josue Chaves on 21/9/18.
//

#ifndef MPOINTER_MPOINTER_H
#define MPOINTER_MPOINTER_H

#include "iostream";


template <typename T>
class MPointer {

private:
    T num1;
    T num2;

public:
    void New( T nu1, T nu2 ){ num1 = nu1; num2 = nu2;     std::cout << num1 + num2 << std::endl;  }

};


#endif //MPOINTER_MPOINTER_H
