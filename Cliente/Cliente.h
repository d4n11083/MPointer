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
#include "../DEFINITIONS.h"

class Cliente {

private:
    int client_socket;                        /// Socket
    bool salir;                         //Booleano para mantener vivo el cliente
    const int bufsize = 1024;           // Tamaño de las palabras
    char* buffer = new char(bufsize);   //Caracteres que se envian y se reciben
    char a;

    struct sockaddr_in server_addr;
    socklen_t size;

public:
    Cliente(sockaddr_in server_addr);
    ~Cliente();
    void iniciar();
    void ejecutar();
    void detener();
};


#endif //MPOINTER_CLIENTE_H
