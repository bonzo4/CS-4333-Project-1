#include <iostream>

void handle_help(const char* program_name) {
    std::cout << "HELP" << std::endl;   
    std::cout << "Usage: " << program_name << " [-h hostname] [-s] [-a hostname] [-p port]" << std::endl;
    std::cout << "  -h hostname : run in client mode connecting to hostname (default: localhost)" << std::endl;
    std::cout << "  -s          : run in server mode" << std::endl;
    std::cout << "  -a hostname : run in auto mode first running in client mode to hostname (default: localhost)" << std::endl;
    std::cout << "                if connection fails, run in server mode" << std::endl;
    std::cout << "  -p port     : specify port number (default: 12987)" << std::endl;
}