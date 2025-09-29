#include "Server.hpp"

void Server::receive_client_info() {
    char buffer[256];
    ssize_t bytes_received = recv(remote_socket_fd, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received > 0) {
        buffer[bytes_received] = '\0';
        string client_info(buffer);
        size_t colon_pos = client_info.find(':');
        if (colon_pos != string::npos) {
            remote_hostname = client_info.substr(0, colon_pos);
            remote_port = stoi(client_info.substr(colon_pos + 1));
        }
    }
}