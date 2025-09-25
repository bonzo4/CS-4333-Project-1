#include "handlers.hpp"



void handle_auto(const string& hostname, int port) {
    try {
        cout << "[INFO] Running in auto mode..." << endl;
        cout << "[INFO] Trying client mode..." << endl;
        handle_client(hostname, port);
    } catch (const exception& e) {
        cerr << "[ERROR] Client mode failed: " << e.what() << endl;
        cout << "[INFO] Falling back to server mode..." << endl;
        handle_server(port);
    }
}