
#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>
#include <sys/socket.h>
#include <unistd.h>

using namespace std;

class Client {
    public:
        Client(const string& hostname, int port) 
            : hostname(hostname), 
              port(port), 
              server_socket(socket(AF_INET, SOCK_STREAM, 0)) {}

        ~Client() {
            if (server_socket >= 0) {
                close(server_socket);
            }
        }

        void run();
    private:
        int server_socket;
        int port;
        string hostname;
        fd_set client_fds;

        void connect_to_server();
};

#endif // CLIENT_HPP