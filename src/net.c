//
// Created by jona on 10/14/20.
//

#include "net.h"

int open_tcp_socket(struct sockaddr_in addr, int sockaddr_len) {
    int fd = socket(AF_INET, SOCK_STREAM, 0);

    if (fd < 0) {
        return SOCKET_FAILED_SOCKET;
    }

    //TODO set timeout values? See setsockopt(3)

    int connection_successful = connect(fd, (struct sockaddr *) &addr, sockaddr_len);

    if (connection_successful < 0) {
        return SOCKET_FAILED_CONNECT;
    }

    return fd;
}