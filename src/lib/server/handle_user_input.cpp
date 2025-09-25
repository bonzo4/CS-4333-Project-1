#include "server.hpp"

#include <sys/socket.h>
#include <unistd.h>
#include <iostream>

bool Server::handle_user_input() {
    string message;
    getline(cin, message);

    if (message.empty()) {
        return true;
    }   
    
    string upper_message = message;
    for (char &c : upper_message) {
        c = toupper(c);
    }

    if (upper_message == "QUIT") {
        cout << "[INFO] Exiting..." << endl;
        return false;
    }

    if (upper_message == "STATUS") {
        if (is_client_connected) {
            cout << "[INFO] Client is connected." << endl;
        } else {
            cout << "[INFO] No client connected." << endl;
        }
        return true;
    }

    message += "\n";

    if (!is_client_connected) {
        cout << "[WARN] No client connected. Message not sent." << endl;
        return true;
    }

    send(client_socket, message.c_str(), message.size(), 0);

    return true;
}