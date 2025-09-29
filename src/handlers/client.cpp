#include "handlers.hpp"
#include "../utils/utils.hpp"
#include "../lib/client/Client.hpp"

void handle_client(const string& hostname, int port) {
    cout << "[INFO] Running in client mode..." << endl;
    Client client(hostname, port);
    client.run();
}