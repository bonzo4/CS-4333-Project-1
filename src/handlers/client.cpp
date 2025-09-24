#include "handlers.hpp"

#include "../lib/client/client.hpp"

void handle_client(const string& hostname, int port) {
    Client client(hostname, port);
    client.run();
}