#include "client.hpp"

#include <sys/socket.h>
#include <unistd.h>
#include <iostream>

void Client::run() {
    connect_to_server();

    cout << "[INFO] Connected to server." << endl;
}