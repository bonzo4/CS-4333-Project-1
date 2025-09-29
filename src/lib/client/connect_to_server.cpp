#include "Client.hpp"

#include <netdb.h>
#include <cstring>
#include <iostream>
#include <sys/socket.h>

void Client::connect_to_server() {
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(remote_port);

    struct hostent* server = gethostbyname(remote_hostname.c_str());
    
    if (server == nullptr) {
        throw runtime_error("Host not found");
    }

    memcpy(&serverAddress.sin_addr, server->h_addr, server->h_length);

    // Set socket timeout for connection (5 seconds)
    struct timeval timeout;
    timeout.tv_sec = 5;
    timeout.tv_usec = 0;

    setsockopt(remote_socket_fd, SOL_SOCKET, SO_SNDTIMEO, &timeout, sizeof(timeout));

    if (connect(remote_socket_fd, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0){
        throw runtime_error("Client unable to communicate with server");
    }

    is_connected = true;
}