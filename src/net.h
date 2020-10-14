//
// Created by jona on 10/14/20.
//

#ifndef SRC_NET_H
#define SRC_NET_H

#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define SOCKET_FAILED_CREATE  -1
#define SOCKET_FAILED_CONNECT -2

#define BAD_IP -1;
int open_tcp_socket(struct sockaddr_in addr, int sockaddr_len);
struct sockaddr_in get_in_addr(char ip[], unsigned short port);
#endif //SRC_NET_H

