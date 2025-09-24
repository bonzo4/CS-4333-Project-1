
#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>

using namespace std;

class Client {
    public:
        Client(const string& hostname, int port);
        ~Client();
        void run();
    private:
        int client_socket;
        int port;
        std::string hostname;
        void connect_to_server();
};

#endif // CLIENT_HPP