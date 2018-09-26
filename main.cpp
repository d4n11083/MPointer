#include <iostream>
#include "Cliente/Cliente.h"
#include "MPointer.h"
#include "typeinfo"
#include "Cliente/JSON/json.hpp"

using json =  nlohmann::json;

int main() {

    int a = 0;
    char t = 'e';

    //MPointer<int > ptr  = MPointer<int >::New();
    //MPointer<int > ptr1 = MPointer<int >::New();
    //MPointer<int > ptr3 = MPointer<int >::New();

    json solicitud;

    solicitud["Solicitud"] = 1;
    std::string stringEnviar = solicitud.dump();
    char *mensajejsonchar = &stringEnviar[0u];




    //std::cout << typeid(ptr).name() << std::endl;


//    MPointer<int > ptr = MPointer<int >::New();
//    std::cout << "###################" << std::endl;
//
//    ptr.operator*(7);
//    std::cout << ptr.operator&() << std::endl;
//
//    std::cout << ptr.operator&() << std::endl;
//    std::cout << ptr.operator&() << std::endl;
//
//    ptr.operator*(4);
//    std::cout << ptr.operator&() << std::endl;
//
//


//      std::cout << ptr.operator&() << std::endl;

//    int z = ptr.operator&();
//    std::cout<< "Imprimiendo z" << std::endl;
//    std::cout << z;




    Cliente* cliente = new Cliente(sockaddr_in());
    cliente->iniciar();
    cliente->enviaDatos(mensajejsonchar);
    std::cout << cliente->recibe(1024);
    std::cout << "\n" <<std::endl;
    cliente->enviaDatos(mensajejsonchar);

    std::cout << cliente->recibe(1024);
    cliente->enviaDatos("HOLA MUNDO 1 OMG");
    std::cout << cliente->recibe(1024);


    return 0;
}
