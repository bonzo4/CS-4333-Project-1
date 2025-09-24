#include "utils.hpp"

void parse_args(int argc, char* argv[], Config& config) {
    config.mode = Mode::HELP;
    config.hostname = "localhost";
    config.port = 12987;

    for (int i = 1; i < argc; ++i) {
        string arg = argv[i];
        if (arg == "-h") {
            config.mode = Mode::CLIENT;
            if (i + 1 < argc) config.hostname = argv[++i];
        } else if (arg == "-s") {
            config.mode = Mode::SERVER;
        } else if (arg == "-a") {
            config.mode = Mode::AUTO;
            if (i + 1 < argc) config.hostname = argv[++i];
        } else if (arg == "-p") {
            if (i + 1 < argc) config.port = std::stoi(argv[++i]);
        } else if (arg == "--help") {
            config.mode = Mode::HELP;
        }
    }
}