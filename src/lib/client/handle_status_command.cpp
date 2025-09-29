#include "Client.hpp"

void Client::handle_status_command() {
    cout << "\n[STATUS] Client: " << hostname << ":" << port << " Server: " << remote_hostname << ":" << remote_port << endl;
}