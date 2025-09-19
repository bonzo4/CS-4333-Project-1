#include <iostream>

void handle_auto(const char* hostname, int port) {
    std::cout << "AUTO" << std::endl;
    std::cout << "Hostname: " << hostname << std::endl;
    std::cout << "Port: " << port << std::endl;
}