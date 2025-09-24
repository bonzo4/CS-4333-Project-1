#include "handlers.hpp"

#include <iostream>

void handle_auto(std::string hostname, int port) {
    try {
        std::cout << "Running in client mode..." << std::endl;
        handle_client(hostname, port);
    } catch (const std::exception& e) {
        std::cerr << "Client mode failed: " << e.what() << std::endl;
        std::cout << "Falling back to server mode..." << std::endl;
        handle_server(port);
    }
}