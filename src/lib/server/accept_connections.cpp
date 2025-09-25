#include "server.hpp"

#include <sys/socket.h>
#include <iostream>

void Server::accept_connections() {
    listen(server_socket, 1);

    client_socket = accept(server_socket, nullptr, nullptr);

    if (client_socket < 0) {
        throw runtime_error("Failed to accept connection");
    }
    is_client_connected = true;
}