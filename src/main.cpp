#include <iostream>
#include "handlers/handlers.hpp"
#include "handlers/server/server.hpp"
#include "handlers/client/client.hpp"

enum class Mode { CLIENT, SERVER, AUTO, HELP };

int main(int argc, char* argv[]) {
    Mode mode = Mode::HELP;
    const char* hostname = "localhost";
    int port = 12987;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "-h") {
            mode = Mode::CLIENT;
            if (i + 1 < argc) hostname = argv[++i];
        } else if (arg == "-s") {
            mode = Mode::SERVER;
        } else if (arg == "-a") {
            mode = Mode::AUTO;
            if (i + 1 < argc) hostname = argv[++i];
        } else if (arg == "-p") {
            if (i + 1 < argc) port = std::stoi(argv[++i]);
        } else if (arg == "--help") {
            mode = Mode::HELP;
        }
    }

    switch (mode) {
        case Mode::CLIENT:
            handle_client(hostname, port);
            break;
        case Mode::SERVER:
            handle_server(port);
            break;
        case Mode::AUTO:
            handle_auto(hostname, port);
            break;
        case Mode::HELP:
            handle_help(argv[0]);
            break;
    }
}