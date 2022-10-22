#ifndef __SERVER_H__
#define __SERVER_H__

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>

#include <time.h>

#include <assert.h>

#include <stdlib.h>
#include <stdio.h>

//#include <arpa/inet.h>

void server();

uint16_t get_port_number();

int get_number_of_connections();

#endif