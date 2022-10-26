#ifndef __CLIENT_H__
#define __CLIENT_H__

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>

#include <time.h>

#include <assert.h>

#include <stdlib.h>
#include <stdio.h>

#include <string.h>

#include <arpa/inet.h>

struct sockaddr_in Address_check;

char Chosen_ip4_address[INET_ADDRSTRLEN];

void client();

uint16_t get_port_number_client();

void get_ip4_address();

void handle_communication_client(int Socket);

#endif