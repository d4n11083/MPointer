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

    while(!salir){
        memset(&buffer,0,bufsize);
        //recv(client_socket,buffer, sizeof(buffer),0);
        send(client_socket,"Hola cliente ",10,0);
        close(client_socket);
    }

}

//######################

bool Cliente::conn() {


    sock = socket(AF_INET,SOCK_STREAM, 0);
    if( sock == -1 ){
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

    if ( connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0 ){
        perror( "Error: conexion fallida" );
        return 1;
    }

    std::cout << "Servidor Conectado\n";
    return true;
}

bool Cliente::enviaDatos(std::string data) {

    if( send(sock, data.c_str(), strlen(data.c_str() ), 0  ) < 0  ){
        perror("Error: envio de datos fallido ");
        return false;
    }
    std::cout << "Datos enviados\n";
    return true;

}

std::string Cliente::recibe(int size = 512) {
    char buffer[size];
    std::string reply;

    if( recv( sock, buffer, sizeof(buffer), 0 ) < 0 ){
        puts("Entrega Fallida");
    }

    reply = buffer;
    return reply;
}


//######################