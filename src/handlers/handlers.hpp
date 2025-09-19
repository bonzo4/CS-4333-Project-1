#ifndef HANDLERS_HPP
#define HANDLERS_HPP

void handle_client(const char* hostname, int port);
void handle_server(int port);
void handle_auto(const char* hostname, int port);
void handle_help(const char* program_name);

#endif