#ifndef HANDLERS_HPP
#define HANDLERS_HPP

#include "client/client.hpp"
#include "server/server.hpp"

void handle_auto(const char* hostname, int port);
void handle_help(const char* program_name);

#endif