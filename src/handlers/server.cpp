#include "handlers.hpp"

#include "../lib/server/server.hpp"

void handle_server(int port) {
    Server server(port);
    server.run();
}