#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

using namespace std;

void handle_server(int port)
{
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));

    listen(server_socket, 5);

    int client_socket = accept(server_socket, nullptr, nullptr);

    char buffer[1024] = { 0 };
    recv(client_socket, buffer, sizeof(buffer), 0);
    cout << "Message from client: " << buffer
              << endl;

    close(server_socket);
}