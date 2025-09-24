#include "client.hpp"
#include <sys/socket.h>
#include <unistd.h>
#include <stdexcept>

Client::Client(const string& hostname, int port) : hostname(hostname), port(port) {
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        throw runtime_error("Failed to create socket");
    }
}

Client::~Client() {
    close(client_socket);
}