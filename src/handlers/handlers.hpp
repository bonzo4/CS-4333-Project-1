#ifndef HANDLERS_HPP
#define HANDLERS_HPP

#include <string>

using namespace std;

void handle_client(const string& hostname, int port);
void handle_server(int port);
void handle_auto(const string& hostname, int port);
void handle_help(const char* program_name);

#endif