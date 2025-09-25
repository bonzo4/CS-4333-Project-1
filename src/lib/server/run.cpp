#include "server.hpp"

#include <sys/select.h>
#include <unistd.h>
#include <iostream>

void Server::run() {
    bind_to_port();

    cout << "[INFO] Server listening on port " << port << "..." << endl;


    while (true) {
        FD_ZERO(&server_fds);
        FD_SET(server_socket, &server_fds);
        FD_SET(client_socket, &server_fds);
        FD_SET(STDIN_FILENO, &server_fds);

        int max_fd = max(server_socket, max(client_socket, STDIN_FILENO));
        int activity = select(max_fd + 1, &server_fds, nullptr, nullptr, nullptr);
        if (activity < 0) {
            throw runtime_error("Select error on server");
        }

        if (FD_ISSET(server_socket, &server_fds)) {
            accept_connections();
            cout << "[INFO] Client connected." << endl;
        }

        if (FD_ISSET(client_socket, &server_fds)) {
            if (!handle_client_message()) break;
        }

        if (FD_ISSET(STDIN_FILENO, &server_fds)) {
            if (!handle_user_input()) break;
        }
    }
}