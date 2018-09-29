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

    T* puntero = nullptr;  //Reserva del espacio del dato de tipo T, cuando se accede al operador *
    int idMpointer;        //ID de Mpointer
    int idMpointerGB;      //ID del GB
    int idMpointerServer;  //ID del Server

    static int cantidadMPointers;  //Cantidad de MPointers

public:

    //Constructor de la clase
    MPointer();

    //Método estático de New()
    static MPointer<T> New();

    //Sobrecarga de los operadores
    T operator*(T pMpointer);
    T operator&();

    //Sobreescritura del operador =
    T operator=( T elemento1);
    T operator=( MPointer<T> pMpointer );

    std::string MPointerInfo ();
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
std::string MPointer<T>::MPointerInfo() {

    std::cout <<"\tCantidad Mpointers: " <<  cantidadMPointers << std::endl;
    std::cout << "**********************************************" << std::endl;
    std::cout <<"IdMpointer: " << idMpointer << std::endl;
    std::cout <<"IdMPointerGB: " << idMpointerGB << std::endl;
    std::cout <<"IdServer: " << idMpointerServer << std::endl;
    if( puntero != nullptr ){
        std::cout << "Valor Almacenado: "<< *puntero << std::endl;
    }
    std::cout << "**********************************************" << std::endl;
}


/**
 * LLama al constructor de la clase.
 * @tparam T tipo de dato
 * @return
 */
template <typename T>
MPointer<T> MPointer<T>::New(){

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

    if( typeid(*puntero) == typeid(elemento1) ){
        std::cout << "LOS DOS SON DEL MISMO TIPO INTERNAMENTE" << std::endl;
        this->operator*(elemento1);
    }else{
        std::cout << "SON DE DIFERENTE TIPO" << std::endl;
    }
}

/**
 * Sobrecarga del operador "="
 * Verifica el  tipo de los operandos son de MPointer
 *
 * @tparam T tipo de dato
 * @param elemento1 elemento a la izquierda de =
 * @param elemento2 elemento a la derecha de =
 * @return
 */
template<typename T >
T MPointer<T>::operator=(MPointer<T> pMPointer){

    if( typeid(pMPointer) == typeid(MPointer<T>) ) {
        this->idMpointerServer = pMPointer.idMpointerServer;
        this->idMpointer = pMPointer.idMpointer;
        this->idMpointerGB = pMPointer.idMpointerGB;
        *(this->puntero) = *(pMPointer.puntero);
    } else{
        std::cout << "No son de tipo MPointer." << std::endl;
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
