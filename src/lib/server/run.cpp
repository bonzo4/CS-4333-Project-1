#include "server.hpp"

#include <sys/select.h>
#include <unistd.h>
#include <iostream>

void Server::run() {
    bind_to_port();

    cout << "[INFO] Server listening on port " << port << "..." << endl;

    accept_connections();

    cout << "[INFO] Client connected." << endl;
}