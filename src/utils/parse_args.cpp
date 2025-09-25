#include "utils.hpp"

#include <stdexcept>
#include <algorithm>

void parse_args(int argc, char* argv[], Config& config) {
    config.mode = Mode::HELP;
    config.hostname = "localhost";
    config.port = 12987;

    bool is_mode_set = false;

    for (int i = 1; i < argc; ++i) {
        string arg = argv[i];
        if (arg == "-h") {
            if (is_mode_set) {
                throw invalid_argument("Multiple modes specified");
            }
            config.mode = Mode::CLIENT;
            is_mode_set = true;
            if (i + 1 < argc && argv[i + 1][0] != '-') {
                config.hostname = argv[++i];
            }
        } else if (arg == "-s") {
            if (is_mode_set) {
                throw invalid_argument("Multiple modes specified");
            }
            config.mode = Mode::SERVER;
            is_mode_set = true;
        } else if (arg == "-a") {
            if (is_mode_set) {
                throw invalid_argument("Multiple modes specified");
            }
            config.mode = Mode::AUTO;
            is_mode_set = true;
            if (i + 1 < argc && argv[i + 1][0] != '-') {
                config.hostname = argv[++i];
            }
        } else if (arg == "-p") {
            if (i + 1 < argc && argv[i + 1][0] != '-') {
                string portStr = argv[i + 1];
                if (all_of(portStr.begin(), portStr.end(), ::isdigit)) {
                    config.port = stoi(portStr);
                    ++i;
                } else {
                    throw invalid_argument("Port must be a number");
                }
            } else {
                throw invalid_argument("Port number not specified");
            }
        } else if (arg == "--help") {
            config.mode = Mode::HELP;
            break;
        }
    }
}