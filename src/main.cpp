#include <iostream>
#include "handlers/handlers.hpp"
#include "utils/utils.hpp"

void run_app(int argc, char* argv[]) {
    Config config;
    parse_args(argc, argv, config);

    switch (config.mode) {
        case Mode::CLIENT:
            handle_client(config.hostname, config.port);
            break;
        case Mode::SERVER:
            handle_server(config.port);
            break;
        case Mode::AUTO:
            handle_auto(config.hostname, config.port);
            break;
        case Mode::HELP:
            handle_help(argv[0]);
            break;
    }
}

int main(int argc, char* argv[]) {
    try {
        run_app(argc, argv);
    } catch (const exception& e) {
        cerr << "[ERROR] " << e.what() << endl;
        cout << "[INFO] Exiting..." << endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}