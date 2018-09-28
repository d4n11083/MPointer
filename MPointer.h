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

    T* puntero = nullptr;
    int prueba;
    int idMpointer;
    int idMpointerGB;
    int idMpointerServer;

    static int cantidadMPointers;

public:

    MPointer();
    std::string pruebas();
    static MPointer<T> New();
    T operator*(T pMpointer);
    T operator&();
    T operator=( T elemento1);
};
//##################################################################################

/**
 * Inicialización del entero cantidadMPointers como variable estatica para conocer la cantidad
 * de MPointer en cualquier momento.
 * @tparam T
 */
template <typename T>
int MPointer<T>::cantidadMPointers = 0;


template<typename T>
std::string MPointer<T>::pruebas() {

    std::cout <<"Cantidad Mpointers: " <<  cantidadMPointers << std::endl;
    std::cout <<"Id: " << prueba << std::endl;



    if( puntero == nullptr ){
        std::cout << puntero << std::endl;
        return "Puntero es Nulo";
    }else{
        std::cout << prueba;
        return "Puntero no es Nulo";
    }

}


/**
 * LLama al constructor de la clase.
 * @tparam T tipo de dato
 * @return
 */
template <typename T>
MPointer<T> MPointer<T>::New(){
    std::cout <<"Se ha creado un nuevo MPointer con ID: " << cantidadMPointers << std::endl;


    return MPointer();
}

/**
 * Inicializa el puntero, añade un ID al MPointer
 * @tparam T tipo de dato que va a ser guardado
 */

template <typename T>
MPointer<T>::MPointer(){
    puntero = (T*)calloc(1, sizeof(T));
    idMpointer= cantidadMPointers;
    cantidadMPointers++;
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
template<typename T >
T MPointer<T>::operator=(T elemento1){
    if( typeid(elemento1) == typeid(this) ) {
        std::cout << "LOS DOS SON MPOINTERS" << std::endl;
    }
    if( typeid(*puntero) == typeid(elemento1) ){
        std::cout << "LOS DOS SON DEL MISMO TIPO INTERNAMENTE" << std::endl;
    }else{
        std::cout << "SON DE DIFERENTE TIPO" << std::endl;
    }
}


template <typename T>
T MPointer<T>::operator*( T pMpointer) {
    if(puntero != NULL){
        *this->puntero = pMpointer;
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
