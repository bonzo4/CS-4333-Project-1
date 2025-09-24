#ifndef SERVER_HPP
#define SERVER_HPP

class Server {
    public:
        Server(int port);
        ~Server();
        void run();
    private:
        int server_socket;
        int port;
        void bind_socket();
};

#endif // SERVER_HPP