#include "handlers.hpp"

#include <iostream>

void handle_auto(const string& hostname, int port) {
    try {
        cout << "Running in client mode..." << endl;
        handle_client(hostname, port);
    } catch (const exception& e) {
        cerr << "Client mode failed: " << e.what() << endl;
        cout << "Falling back to server mode..." << endl;
        handle_server(port);
    }
}