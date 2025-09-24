#include "server.hpp"

#include <sys/socket.h>
#include <unistd.h>

Server::Server(int port) : port(port) {
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
}

Server::~Server() {
    close(server_socket);
}