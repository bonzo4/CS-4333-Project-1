#include "client.hpp"

#include <sys/socket.h>
#include <unistd.h>
#include <iostream>

bool Client::handle_user_input() {
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
        cout << "[STATUS] Client: " << hostname << ":" << port << " Server: NONE" << endl;
        return true;
    }

    message += "\n";

    send(server_socket, message.c_str(), message.size(), 0);

    return true;
}