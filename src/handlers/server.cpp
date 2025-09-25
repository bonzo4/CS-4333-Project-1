#include "handlers.hpp"

#include "../lib/server/server.hpp"

void handle_server(int port) {
    cout << "[INFO] Running in server mode..." << endl;
    Server server(port);
    server.run();
}