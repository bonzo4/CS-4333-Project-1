#include "Client.hpp"

void Client::handle_status_command() {
    if (is_connected) {
        cout << "\n[STATUS] Client: " << hostname << ":" << port << " Server: " << remote_hostname << ":" << remote_port << endl;
    } else {
        cout << "\n[STATUS] Client: " << hostname << ":" << port << " Server: NONE" << endl;
    }
}