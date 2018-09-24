#include <iostream>
#include "Cliente/Cliente.h"
#include "MPointer.h"
int main() {

    MPointer<int > ptr = MPointer<int >::New();
    std::cout << "###################" << std::endl;

    Cliente* cliente = new Cliente(sockaddr_in());
    cliente->iniciar();
    cliente->enviaDatos("Este mensaje fue enviado desde el cliente");
    std::cout << cliente->recibe(1024);
    return 0;
}
