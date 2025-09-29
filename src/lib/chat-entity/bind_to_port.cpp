#include "ChatEntity.hpp"

#include <netinet/in.h>
#include <iostream>

void ChatEntity::bind_to_port() {
    sockaddr_in chatAddress;
    chatAddress.sin_family = AF_INET;
    chatAddress.sin_port = htons(port);
    chatAddress.sin_addr.s_addr = INADDR_ANY;

    if (bind(socket_fd, (struct sockaddr*)&chatAddress, sizeof(chatAddress)) < 0) {
        throw runtime_error("Server unable to listen on specified port");
    }

    if (port == 0) {
        socklen_t len = sizeof(chatAddress);
        if (getsockname(socket_fd, (struct sockaddr*)&chatAddress, &len) == -1) {
            throw runtime_error("Unable to get assigned port");
        }
        port = ntohs(chatAddress.sin_port);
    }
}