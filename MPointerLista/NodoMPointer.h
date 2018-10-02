//
// Created by Josue Chaves on 10/1/18.
//

#ifndef MPOINTER_NODOMPOINTER_H
#define MPOINTER_NODOMPOINTER_H

#include "../MPointer.h"

typedef int Elem;

class NodoMPointer{

private:

    Elem elem;

    //Se crean los MPointer a sig y a prev.
    MPointer<NodoMPointer> sig = MPointer<NodoMPointer>::New();
    MPointer<NodoMPointer> prev = MPointer<NodoMPointer>::New();

    friend class ListaMPointer;

};


#endif //MPOINTER_NODOMPOINTER_H
