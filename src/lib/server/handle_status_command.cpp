#include "Server.hpp"

void Server::handle_status_command() {
    if (is_client_connected) {
        cout << "\n[STATUS] Client: " << remote_hostname << ":" << remote_port << " Server: " << hostname << ":" << port << endl;
    } else {
        cout << "\n[STATUS] Client: NONE" << " Server: " << hostname << ":" << port << endl;

    }
}