#include "Server.hpp"

#include <sys/socket.h>
#include <iostream>

void Server::accept_connections() {
    remote_socket_fd = accept(socket_fd, nullptr, nullptr);

    if (remote_socket_fd < 0) {
        throw runtime_error("Failed to accept connection");
    }
    is_client_connected = true;
}