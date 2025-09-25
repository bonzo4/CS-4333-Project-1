#include "client.hpp"

#include <sys/socket.h>
#include <unistd.h>
#include <iostream>

void Client::run() {
    connect_to_server();

    cout << "[INFO] Connected to server: " << hostname << ":" << port << endl;

    while (true) {
        FD_ZERO(&client_fds);
        FD_SET(STDIN_FILENO, &client_fds);
        FD_SET(server_socket, &client_fds);

        int max_fd = max(STDIN_FILENO, server_socket) + 1;
        int activity = select(max_fd, &client_fds, nullptr, nullptr, nullptr);

        if (activity < 0) {
            throw runtime_error("Select error");
        }

        if (FD_ISSET(STDIN_FILENO, &client_fds)) {
            if (!handle_user_input()) break;
        }

        if (FD_ISSET(server_socket, &client_fds)) {
            if (!handle_server_message()) break;
        }
    }
}