#include "client.hpp"
#include <sys/socket.h>
#include <unistd.h>
#include <stdexcept>

using std::runtime_error;

Client::Client(std::string hostname, int port) : hostname(std::move(hostname)), port(port) {
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        throw std::runtime_error("Failed to create socket");
    }
}

Client::~Client() {
    close(client_socket);
}