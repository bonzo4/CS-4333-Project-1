#include "ChatEntity.hpp"

Command ChatEntity::process_command(const string& input) {
    string upper_command = input;
    for (char &c : upper_command) {
        c = toupper(c);
    }

    if (upper_command == "QUIT") {
        cout << "\n[INFO] Exiting..." << endl;
        return Command::QUIT;
    }

    if (upper_command == "STATUS") {
        handle_status_command();
        cout << "> ";
        input_in_progress = true;
        current_input.clear();
        return Command::STATUS;
    }

    return Command::UNKNOWN;
}