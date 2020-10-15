//
// Created by jona on 10/14/20.
//

#include "net.h"
int open_tcp_socket(struct sockaddr_in addr, int sockaddr_len) {
    int fd = socket(AF_INET, SOCK_STREAM, 0);

    if (fd < 0) {
        return SOCKET_FAILED_CREATE;
    }

    // TODO set timeout values? See setsockopt(3)

    int connection_successful = connect(fd, (struct sockaddr *) &addr, sockaddr_len);

    if (connection_successful < 0) {
        return SOCKET_FAILED_CONNECT;
    }

    return fd;
}

int get_in_addr(const char ip[], unsigned short port, struct sockaddr_in *socket_location) {
    //check that the ip is ok or not
    int ip_ok = inet_aton(ip, &socket_location->sin_addr);   
    if (!ip_ok) {
        return BAD_IP;
    }
    //this is basically like doing *(socket_location).sin_family = AF_INET;
    socket_location->sin_family = AF_INET;
    socket_location->sin_port = htons(port);
    return 0;    
}
