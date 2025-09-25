#include "server.hpp"

#include <sys/socket.h>
#include <unistd.h>
#include <iostream>

bool Server::handle_client_message() {
    string buffer(1024, '\0');
    ssize_t bytes_received = recv(client_socket, buffer.data(), buffer.size() - 1, 0);
    if (bytes_received <= 0) {
        cout << "[INFO] Client disconnected." << endl;
        return false;
    } 
    buffer[bytes_received] = '\0';
    cout << "[remote] " << buffer;
    return true;
}