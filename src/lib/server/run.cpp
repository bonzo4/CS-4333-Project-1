#include "server.hpp"

#include <iostream>
#include <sys/socket.h>

using namespace std;

void Server::run() {
    bind_socket();

    listen(server_socket, 5);

    int client_socket = accept(server_socket, nullptr, nullptr);

    char buffer[1024] = { 0 };
    recv(client_socket, buffer, sizeof(buffer), 0);
    cout << "Message from client: " << buffer << endl;
}