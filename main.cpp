#include <iostream>
#include "MPointer.h"
int main() {

    MPointer<int> New = MPointer::New(2,3);


    std::cout << "Hello, World!" << std::endl;
    return 0;
}