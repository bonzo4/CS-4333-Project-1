#include "ChatEntity.hpp"

#include <sys/socket.h>
#include <unistd.h>
#include <iostream>
#include <termios.h>

bool ChatEntity::handle_user_input() {
    char ch;
    ssize_t bytes_read = read(STDIN_FILENO, &ch, 1);
    
    if (bytes_read <= 0) {
        return false;
    }
    
    if (ch == '\n') {
        input_in_progress = false;
        
        if (current_input.empty()) {
            cout << "[Warning] Empty input, please type a message or command." << endl;
            cout << "> ";
            cout.flush();
            input_in_progress = true;
            return true;
        }

        Command cmd = process_command(current_input);
        if (cmd == Command::QUIT) {
            return false;
        } else if (cmd == Command::STATUS) {
            return true;
        }

        string message = current_input + "\n";
        send(remote_socket_fd, message.c_str(), message.size(), 0);
        
        current_input.clear();
        cout << "\n> ";
        cout.flush();
        input_in_progress = true;
    } else if (ch == 127 || ch == '\b') {
        if (!current_input.empty()) {
            current_input.pop_back();
            cout << "\b \b";
            cout.flush();
        }
    } else if (ch >= 32 && ch <= 126) {
        if (!input_in_progress) {
            cout << "> ";
            cout.flush();
            input_in_progress = true;
        }
        current_input += ch;
        cout << ch;
        cout.flush();
    }
    
    return true;
}