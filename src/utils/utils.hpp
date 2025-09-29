#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <termios.h>

using namespace std;

// Forward declaration for ChatEntity
class ChatEntity;

enum class Mode { CLIENT, SERVER, AUTO, HELP };

struct Config {
    Mode mode;
    string hostname;
    int port;
};

static struct termios original_termios;

void parse_args(int argc, char* argv[], Config& config);

#endif // UTILS_HPP