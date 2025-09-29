#include "Client.hpp"

#include <sys/socket.h>
#include <unistd.h>
#include <iostream>
#include <termios.h>
#include <cstdlib>
#include <netinet/in.h>

void Client::run() {
    bind_to_port();

    connect_to_server();

    string init_message = hostname + ":" + to_string(port) + "\n";
    send(remote_socket_fd, init_message.c_str(), init_message.size(), 0);

    cout << "[INFO] Connected to server: " << remote_hostname << ":" << remote_port << endl;
        
    setup_terminal();

    cout << "> ";
    cout.flush();
    input_in_progress = true;

    while (true) {
        FD_ZERO(&fds);
        FD_SET(STDIN_FILENO, &fds);
        FD_SET(remote_socket_fd, &fds);

        int max_fd = max(STDIN_FILENO, remote_socket_fd) + 1;
        int activity = select(max_fd, &fds, nullptr, nullptr, nullptr);

        if (activity < 0) {
            restore_terminal();
            throw runtime_error("Select error");
        }

        if (FD_ISSET(STDIN_FILENO, &fds)) {
            if (!handle_user_input()) {
                restore_terminal();
                break;
            }
        }

        if (FD_ISSET(remote_socket_fd, &fds)) {
            if (!handle_remote_message()) {
                restore_terminal();
                break;
            }
        }
    }
}