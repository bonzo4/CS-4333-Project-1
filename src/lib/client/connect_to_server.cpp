#include "Client.hpp"

#include <netdb.h>
#include <cstring>
#include <iostream>

void Client::connect_to_server() {
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(remote_port);

    struct hostent* server = gethostbyname(remote_hostname.c_str());
    
    if (server == nullptr) {
        throw runtime_error("Host not found");
    }

    memcpy(&serverAddress.sin_addr, server->h_addr, server->h_length);

    if (connect(remote_socket_fd, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0){
        throw runtime_error("Client unable to communicate with server");
    }
}