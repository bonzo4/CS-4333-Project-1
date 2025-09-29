#include "Server.hpp"

#include <sys/select.h>
#include <unistd.h>
#include <iostream>
#include <netinet/in.h>

void Server::run() {
    bind_to_port();
    
    listen(socket_fd, 1);
    
    cout << "[INFO] Server listening on port " << port << "..." << endl;

    setup_terminal();

    cout << "> ";
    cout.flush();
    input_in_progress = true;

    while (true) {
        FD_ZERO(&fds);
        FD_SET(socket_fd, &fds);
        if (is_client_connected) {
            FD_SET(remote_socket_fd, &fds);
        }
        FD_SET(STDIN_FILENO, &fds);

        int max_fd = max(socket_fd, max(remote_socket_fd, STDIN_FILENO));
        select(max_fd + 1, &fds, nullptr, nullptr, nullptr);

        if (FD_ISSET(socket_fd, &fds)) {
            accept_connections();
            if (input_in_progress) {
                save_and_clear_input();
            }
            cout << "[INFO] Client connected." << endl;
            if (input_in_progress) {
                restore_input();
            }
            is_client_connected = true;
            receive_client_info();
        }

        if (is_client_connected && FD_ISSET(remote_socket_fd, &fds)) {
            if (!handle_remote_message()) {
                restore_terminal();
                is_client_connected = false;
            }
        }

        if (FD_ISSET(STDIN_FILENO, &fds)) {
            if (!handle_user_input()) {
                restore_terminal();
                break;
            }
        }
    }
}