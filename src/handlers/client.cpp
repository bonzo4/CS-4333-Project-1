#include "handlers.hpp"

#include "../lib/client/client.hpp"

void handle_client(std::string hostname, int port) {
    Client client(hostname, port);
    client.run();
}