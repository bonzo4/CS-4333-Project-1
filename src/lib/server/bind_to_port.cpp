#include "server.hpp"

#include <iostream>
#include <netinet/in.h>

void Server::bind_to_port() {
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        throw runtime_error("Server unable to listen on specified port");
    }
}