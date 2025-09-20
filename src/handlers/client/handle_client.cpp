#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

void handle_client(const char* hostname, int port) {
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    
    if (connect(client_socket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        close(client_socket);
        throw std::runtime_error("Client unable to communicate with server");
    }

    const char* message = "Hello, server!";
    send(client_socket, message, strlen(message), 0);

    close(client_socket);
}