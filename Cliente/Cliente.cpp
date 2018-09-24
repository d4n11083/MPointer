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
    conn();
}

//######################

bool Cliente::conn() {


    if( client_socket == -1 ){
        perror("No se pudo conectar el socket");
    }
    std::cout << "Socket creado \n" << std::endl;


    if( inet_addr(DireccionIP.c_str()) == -1){
        struct hostent *he;
        struct in_addr **addr_list;

        if( (he = gethostbyname(DireccionIP.c_str()) ) == NULL){
            herror("gethostbyname");
            std::cout << "No se pudo arreglar el HostName\n";
            return false;
        }

        addr_list = ( struct in_addr ** ) he->h_addr_list;
        for(int i = 0; addr_list[i] != NULL; i++ ){
            server_addr.sin_addr = *addr_list[i];
            std::cout << DireccionIP<< "Resolved to " << inet_ntoa(*addr_list[i])<<std::endl;
            break;
        }
    }
    else{
        server_addr.sin_addr.s_addr = inet_addr( DireccionIP.c_str() );
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons( SERVER_PORT );

    if ( connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0 ){
        perror( "Error: conexion fallida" );
        return 1;
    }

    std::cout << "Servidor Conectado\n";
    return true;
}

bool Cliente::enviaDatos(std::string data) {

    if( send(client_socket, data.c_str(), strlen(data.c_str() ), 0  ) < 0  ){
        perror("Error: envio de datos fallido ");
        return false;
    }
    std::cout << "Datos enviados\n";
    return true;

}

std::string Cliente::recibe(int size = 512) {
    char buffer[size];
    std::string reply;

    if( recv( client_socket, buffer, sizeof(buffer), 0 ) < 0 ){
        puts("Entrega Fallida");
    }

    reply = buffer;
    return reply;
}


//######################