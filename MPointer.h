//
// Created by Josue Chaves on 21/9/18.
//

#ifndef MPOINTER_MPOINTER_H
#define MPOINTER_MPOINTER_H


#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ctime>


template <typename T>
class MPointer {
private:

    T* puntero = NULL;
    T valor = 0;
    int idMpointer;
    int idMpointerGB;
    int idMpointerServer;

    static int cantidadMPointers;

public:

    MPointer();
    static MPointer<T> New();
    T operator*(T pMpointer);
    T operator&();
    T operator=( T elemento1);
};

/**
 * Inicialización del entero cantidadMPointers como variable estatica para conocer la cantidad
 * de MPointer en cualquier momento.
 * @tparam T
 */
template <typename T>
int MPointer<T>::cantidadMPointers = 0;

/**
 * LLama al constructor de la clase.
 * @tparam T tipo de dato
 * @return
 */
template <typename T>
MPointer<T> MPointer<T>::New(){
    MPointer();
    std::cout <<"Se ha creado un nuevo puntero..." << std::endl;
}

/**
 * Inicializa el puntero, añade un ID al MPointer
 * @tparam T tipo de dato que va a ser guardado
 */

template <typename T>
MPointer<T>::MPointer() {
    puntero = (T*)calloc(1, sizeof(T));
    idMpointer = cantidadMPointers;
    cantidadMPointers++;
    std::cout << "Puntero Construido" << std::endl;
}

/**
 * Sobrecarga del operador "="
 * Verifica el  tipo de los operandos
 *
 * @tparam T tipo de dato
 * @param elemento1 elemento a la izquierda de =
 * @param elemento2 elemento a la derecha de =
 * @return
 */
template<typename T>
T MPointer<T>::operator=(T elemento1){



}


template <typename T>
T MPointer<T>::operator*( T pMpointer) {
    if(puntero != NULL){
        valor = pMpointer;
        puntero = &valor;
        std::cout << "Puntero Guardado" << std::endl;
        std::cout << "COUT DE PRUEBA, Imprimiendo el dato guardado: "<< *puntero << std::endl;
    }else {
        std::cout << "Puntero Nulo " << std::endl;
    }
}

template <typename T>
T MPointer<T>::operator&() {
    if (puntero == nullptr){
        std::cout << "Es Nulo" << std::endl;
        return 0;
    }else{
        return *puntero;
    }
}






#endif //MPOINTER_MPOINTER_H
