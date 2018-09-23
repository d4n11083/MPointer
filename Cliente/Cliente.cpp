//
// Created by maesly on 22/09/18.
//

#include "Cliente.h"

Cliente::Cliente(sockaddr_in server_addr) {
    salir = false;
}
Cliente::~Cliente() {}

void Cliente::detener() {
    salir = true;
    shutdown(client_socket,SHUT_RDWR);
}

void Cliente::iniciar() {
    client_socket = socket(AF_INET,SOCK_STREAM,0);
    ejecutar();
}

void Cliente::ejecutar() {

    if(client_socket < 0){
        std::cerr << " Error al crear el socket del cliente " << std::endl;
    }

    std::cout << "Se ha creado el socket del cliente" << std::endl;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET,DIRECCION_IP, &server_addr.sin_addr);

    int conexion = connect(client_socket,(struct sockaddr *) &server_addr, sizeof(server_addr));
    if(conexion == 0){
        std::cout << "Conexion con el servidor\n"
                  << inet_ntoa(server_addr.sin_addr) << std::endl;
    }

    close(client_socket);


}