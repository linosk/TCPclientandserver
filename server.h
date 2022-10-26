#ifndef __SERVER_H__
#define __SERVER_H__

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>

#include <time.h>

#include <assert.h>

#include <stdlib.h>
#include <stdio.h>

#include <string.h>

#include <arpa/inet.h>

void server();

uint16_t get_port_number_server();

int get_number_of_connections();

void handle_communication_server(int Socket);

#endif