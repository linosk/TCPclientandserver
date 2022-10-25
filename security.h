#ifndef __SECURITY_H__
#define __SECURITY_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "server.h"
#include "client.h"

#define LENGTH_CORRECT 6
#define REQUIRED_INPUTS 2

#define ERROR "ERROR"
#define NEEDS_ARGUMENTS "Application needs arguments."
#define TOO_MANY_ARGUMENTS "Too many arguments."
#define HOW_TO_RUN "After './TCPserverandclient' write 'Server' to run server application or 'Client' to run client application."
#define SERVER "Server"
#define CLIENT "Client"
#define WRONG_ARGUMENTS "- is not correct argument."

char Answer[LENGTH_CORRECT];

void check(int Number_of_inputs, char** Inputs);

#endif