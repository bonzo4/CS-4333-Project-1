#include <iostream>

void handle_client(const char* hostname, int port) {
    std::cout << "CLIENT" << std::endl;
    std::cout << "Hostname: " << hostname << std::endl;
    std::cout << "Port: " << port << std::endl;
}