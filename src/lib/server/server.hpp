#ifndef SERVER_HPP
#define SERVER_HPP

#include <sys/socket.h>
#include <unistd.h>

using namespace std;

class Server {
    public:
        Server(int port) 
            : port(port), 
              is_client_connected(false), 
              server_socket(socket(AF_INET, SOCK_STREAM, 0)) {}
              
        ~Server() {
            if (server_socket >= 0) {
                close(server_socket);
            }
            if (client_socket >= 0) {
                close(client_socket);
            }
        }

        void run();
    private:
        int server_socket;
        int client_socket;
        int port;
        fd_set server_fds;
        bool is_client_connected;

        void bind_to_port();
        void accept_connections();
        bool handle_client_message();
        bool handle_user_input();
};

#endif // SERVER_HPP