#include "handlers.hpp"
#include "../utils/utils.hpp"
#include "../lib/server/Server.hpp"

void handle_server(int port) {
    cout << "[INFO] Running in server mode..." << endl;
    Server server(port);
    server.run();
}