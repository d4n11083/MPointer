//
// Created by Josue Chaves on 9/28/18.
//

#ifndef MPOINTER_LISTAMPOINTER_H
#define MPOINTER_LISTAMPOINTER_H

#include "NodoMPointer.h"

/**
 * @file ListaEnlazadaDoble
 * @brief Clase que contiene la Lista Doblemente Enlazada
 * Dentro de esta clase se encuentran los diferentes métodos para hacer
 * uso de la lista Doblemente enlazada
 *
 * @author Josué Chaves Araya
 */

class ListaMPointer {
public:
    ListaMPointer();
    ~ListaMPointer();

    void imprimirLista();
    void insertarFinal( const Elem &e);
    void eliminarFinal();
    bool compareNodos( NodoMPointer nodo1, NodoMPointer nodo2 );
    void insertarElem( NodoMPointer nodo1, Elem e);

private:
    NodoMPointer *realCabezaMPointer;
    NodoMPointer *realColaMPointer;

    MPointer<NodoMPointer> cabezaMPointer = MPointer<NodoMPointer>::New();
    MPointer<NodoMPointer>  colaMPointer = MPointer<NodoMPointer>::New();

protected:
    void insertar( NodoMPointer v, const Elem &e);
    void eliminar( NodoMPointer  );

};





#endif //MPOINTER_LISTAMPOINTER_H
