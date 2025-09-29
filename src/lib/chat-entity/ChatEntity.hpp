#ifndef CHAT_ENTITY_HPP
#define CHAT_ENTITY_HPP

#include <sys/socket.h>
#include <unistd.h>
#include <string>
#include <iostream>

using namespace std;

enum class Command { QUIT, STATUS, UNKNOWN };

class ChatEntity {
    public:
        ChatEntity(int port) 
            : socket_fd(socket(AF_INET, SOCK_STREAM, 0)),
              remote_socket_fd(socket(AF_INET, SOCK_STREAM, 0)),
              hostname("127.0.0.1"),
              port(port),
              remote_hostname("127.0.0.1"),
              remote_port(port),
              current_input(""),
              input_in_progress(false) {}

        ~ChatEntity() {
            if (socket_fd >= 0) {
                close(socket_fd);
            }
            if (remote_socket_fd >= 0) {
                close(remote_socket_fd);
            }
        }

        void stop() {
            if (socket_fd >= 0) {
                close(socket_fd);
                socket_fd = -1;
            }
            if (remote_socket_fd >= 0) {
                close(remote_socket_fd);
                remote_socket_fd = -1;
            }
        }

        void restore_terminal();

        virtual void run() = 0;

    protected:
        int socket_fd;
        int remote_socket_fd;

        string hostname;
        int port;

        string remote_hostname;
        int remote_port;
        
        fd_set fds;

        string current_input;
        bool input_in_progress;

        virtual void handle_status_command() = 0;
        
        bool handle_remote_message();
        bool handle_user_input();
        void bind_to_port();
        void setup_terminal();
        void save_and_clear_input();
        void restore_input();
        Command process_command(const string& input);
};

#endif // CHAT_ENTITY_HPP