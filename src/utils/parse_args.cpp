#include "utils.hpp"

#include <stdexcept>
#include <algorithm>

void parse_args(int argc, char* argv[], Config& config) {
    config.mode = Mode::HELP;
    config.hostname = "127.0.0.1";
    config.port = 12987;

    bool is_mode_set = false;

    auto set_mode = [&](Mode mode) {
        if (is_mode_set) {
            throw std::invalid_argument("Multiple modes specified");
        }
        config.mode = mode;
        is_mode_set = true;
    };

    for (int i = 1; i < argc; ++i) {
        string arg = argv[i];
        if (arg == "-h") {
            set_mode(Mode::CLIENT);
            if (i + 1 < argc && argv[i + 1][0] != '-') {
                config.hostname = (argv[++i] == "localhost") ? "127.0.0.1" : argv[i];
            }
        } else if (arg == "-s") {
            set_mode(Mode::SERVER);
        } else if (arg == "-a") {
            set_mode(Mode::AUTO);
            if (i + 1 < argc && argv[i + 1][0] != '-') {
                config.hostname = (argv[++i] == "localhost") ? "127.0.0.1" : argv[i];
            }
        } else if (arg == "-p") {
            if (argv[i + 1][0] == '-' || i + 1 >= argc) {
                throw invalid_argument("Port number not specified");
            }   

            string portStr = argv[i + 1];
            
            if (!all_of(portStr.begin(), portStr.end(), ::isdigit)) {
                throw invalid_argument("Port must be a number");
            }

            config.port = stoi(portStr);
            ++i;
        } else if (arg == "--help") {
            config.mode = Mode::HELP;
            break;
        }
    }
}