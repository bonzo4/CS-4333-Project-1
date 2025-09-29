#ifndef SERVER_HPP
#define SERVER_HPP

#include "../chat-entity/ChatEntity.hpp"

#include <sys/socket.h>
#include <unistd.h>
#include <string>
#include <iostream>

using namespace std;

class Server : public ChatEntity {
    public:
        Server(int port) : 
            ChatEntity(port), 
            is_client_connected(false) {}

        void run() override;

    private:
        bool is_client_connected;

        void accept_connections();
        void handle_status_command() override;
        void receive_client_info();
};

#endif // SERVER_HPP