#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "../chat-entity/ChatEntity.hpp"

#include <string>
#include <sys/socket.h>
#include <unistd.h>
#include <iostream>

using namespace std;

class Client : public ChatEntity {
    public:
        Client(const string& server_hostname, int server_port) :
            ChatEntity(server_port) {
                port = 0;
                remote_hostname = server_hostname;
            }

        void run() override;

    private:
        void connect_to_server();
        void handle_status_command() override;
};

#endif // CLIENT_HPP