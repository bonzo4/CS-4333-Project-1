#include "ChatEntity.hpp"

bool ChatEntity::handle_remote_message() {
    string buffer(1024, '\0');
    ssize_t bytes_received = recv(remote_socket_fd, buffer.data(), buffer.size() - 1, 0);
    
    if (bytes_received <= 0) {
        if (input_in_progress) {
            save_and_clear_input();
        }
        cout << "[INFO] Remote disconnected." << endl;
        if (input_in_progress) {
            restore_input();
        }
        return false;
    }
    
    buffer[bytes_received] = '\0';
    
    if (input_in_progress) {
        save_and_clear_input();
    }
    
    cout << "[remote] " << buffer;
    
    if (input_in_progress) {
        restore_input();
    }
    
    return true;
}