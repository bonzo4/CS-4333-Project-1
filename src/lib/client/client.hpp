
#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>

class Client {
    public:
        Client(std::string hostname, int port);
        ~Client();
        void run();
    private:
        int client_socket;
        int port;
        std::string hostname;
        void connect_to_server();
};

#endif // CLIENT_HPP