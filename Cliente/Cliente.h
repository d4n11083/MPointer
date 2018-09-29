//
// Created by maesly on 22/09/18.
//

#ifndef MPOINTER_CLIENTE_H
#define MPOINTER_CLIENTE_H

#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <thread>
#include <stdio.h>
#include <netdb.h>
#include "../DEFINITIONS.h"
#include "JSON/json.hpp"
class Cliente {

private:
    int client_socket = -1;                        /// Socket
    bool salir;                         //Booleano para mantener vivo el cliente
    const int bufsize = 1024;           // Tamaño de las palabras
    char* buffer = new char(bufsize);   //Caracteres que se envian y se reciben
    char a;

    struct sockaddr_in server_addr;
    socklen_t size;

    std::string DireccionIP =DIRECCION_IP;
    using json =  nlohmann::json;

    int ID;

public:
    Cliente(sockaddr_in server_addr);
    ~Cliente();
    void iniciar();
    void ejecutar();
    void detener();

    bool conn();
    bool enviaDatos(std::string data);
    std::string recibe(int size);

    void solicitudUno();
    void solicitudDos();
};


#endif //MPOINTER_CLIENTE_H
