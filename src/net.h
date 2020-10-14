//
// Created by jona on 10/14/20.
//

#ifndef SRC_NET_H
#define SRC_NET_H

#include <arpa/inet.h>
#include <sys/socket.h>

#define SOCKET_FAILED_SOCKET  -1
#define SOCKET_FAILED_CONNECT -2

int open_tcp_socket(struct sockaddr_in addr, int sockaddr_len);

#endif //SRC_NET_H
