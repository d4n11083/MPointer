//
// Created by Josue Chaves on 9/28/18.
//

#include "ListaMPointer.h"

Elem contadorNodos = 0;

ListaMPointer::ListaMPointer() {
    realCabezaMPointer = new NodoMPointer;
    realColaMPointer = new NodoMPointer;

    cabezaMPointer.operator*(*realCabezaMPointer);
    colaMPointer.operator*(*realColaMPointer);


    cabezaMPointer.operator&().sig =  colaMPointer.operator&() ;
    colaMPointer.operator&().prev  = cabezaMPointer.operator&() ;

}

ListaMPointer::~ListaMPointer() {
    std::cout << "Aca se debe eliminar la lista" << std::endl;

}

bool ListaMPointer::compareNodos(NodoMPointer nodo1, NodoMPointer nodo2) {
    if( nodo1.elem == nodo2.elem && nodo1.sig.operator&().elem == nodo2.sig.operator&().elem && nodo1.prev.operator&().elem ==
                                                                                                nodo2.prev.operator&().elem){
        return true;
    }else{
        return false;
    }
}

void ListaMPointer::insertarElem(NodoMPointer nodo1, Elem e) {

    nodo1.elem = e;
}

void ListaMPointer::imprimirLista(){
    MPointer<NodoMPointer> indice = MPointer<NodoMPointer>::New();
    indice.operator*( cabezaMPointer.operator&().sig.operator&() );

    do{
        std::cout <<">" << indice.operator&().elem <<  std::endl;
        indice.operator*( indice.operator&().sig.operator&() );
        //indice = indice.operator&().sig;

    }while( !compareNodos(indice.operator&(), colaMPointer.operator&()));

}

void ListaMPointer::insertar(NodoMPointer v, const Elem &e) {

    MPointer<NodoMPointer> nNodo = MPointer<NodoMPointer>::New();
    NodoMPointer realNodo = NodoMPointer();
    nNodo.operator*(realNodo);

    insertarElem( nNodo.operator&(), e );


    nNodo.operator&().sig = v;
    nNodo.operator&().prev = v.prev;

    v.prev.operator&().sig = v.prev.operator&() = nNodo.operator&();

    contadorNodos++;

}

void ListaMPointer::insertarFinal(const Elem &e) {

    insertar( colaMPointer.operator&(), e );

}

