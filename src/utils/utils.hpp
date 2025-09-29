#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <termios.h>

using namespace std;

enum class Mode { CLIENT, SERVER, AUTO, HELP };

struct Config {
    Mode mode;
    string hostname;
    int port;
};

void parse_args(int argc, char* argv[], Config& config);

#endif // UTILS_HPP