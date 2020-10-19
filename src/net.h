//
// Created by jona on 10/14/20.
//

#ifndef SRC_NET_H
#define SRC_NET_H

#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define SOCKET_FAILED_CREATE  -1
#define SOCKET_FAILED_CONNECT -2

#define BAD_IP -1;

int open_tcp_socket(struct sockaddr_in addr, int sockaddr_len);
int get_in_addr(const char ip[], unsigned short port, struct sockaddr_in *socket_location);

#endif //SRC_NET_H

