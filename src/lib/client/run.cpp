#include "client.hpp"

#include <sys/socket.h>

void Client::run() {
    connect_to_server();

    const string message = "Hello, server!";
    send(client_socket, message.c_str(), message.size(), 0);
}