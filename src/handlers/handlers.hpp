#ifndef HANDLERS_HPP
#define HANDLERS_HPP

#include <string>

void handle_client(std::string hostname, int port);
void handle_server(int port);
void handle_auto(std::string hostname, int port);
void handle_help(const char* program_name);

#endif