#include "client.hpp"

#include <netdb.h>
#include <cstring>
#include <iostream>

void Client::connect_to_server() {
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);

    struct hostent* server = gethostbyname(hostname.c_str());
    if (server == nullptr) {
        throw std::runtime_error("Host not found");
    }

    std::memcpy(&serverAddress.sin_addr, server->h_addr, server->h_length);
        
    if (connect(client_socket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0){
        throw std::runtime_error("Client unable to communicate with server");
    }
}