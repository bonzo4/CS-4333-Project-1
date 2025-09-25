#include "client.hpp"
#include <iostream>

bool Client::handle_server_message() {
    string buffer(1024, '\0');
    ssize_t bytes_received = recv(server_socket, buffer.data(), buffer.size() - 1, 0);
    if (bytes_received <= 0) {
        cout << "[INFO] Server disconnected." << endl;
        return false;
    }
    buffer[bytes_received] = '\0';
    cout << "[remote] " << buffer;
    return true;
}