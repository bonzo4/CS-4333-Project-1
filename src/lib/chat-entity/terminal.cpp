#include "ChatEntity.hpp"

#include <iostream>
#include <termios.h>
#include <unistd.h>

static struct termios original_termios;

void ChatEntity::setup_terminal() {
    tcgetattr(STDIN_FILENO, &original_termios);
    struct termios raw = original_termios;
    raw.c_lflag &= ~(ICANON | ECHO);
    raw.c_cc[VMIN] = 1;
    raw.c_cc[VTIME] = 0;
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

void ChatEntity::restore_terminal() {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &original_termios);
}

void ChatEntity::save_and_clear_input() {
    cout << "\r\033[K";
    cout.flush();
}

void ChatEntity::restore_input() {
    cout << "> " << current_input;
    cout.flush();
}