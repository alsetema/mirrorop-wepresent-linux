#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include "net.h"


int socket1;
int socket2;
int socket3;

//fuck i cant remember shit, ask jona
int main(int argc, char *argv[]) {
    const char *ip = "127.0.0.1";
    uint16_t port = 5555;

    struct sockaddr_in remote_addr;
    remote_addr.sin_family = AF_INET;
    remote_addr.sin_addr.s_addr = inet_addr(ip);
    remote_addr.sin_port = htons(port);

    int fd = open_tcp_socket(remote_addr, sizeof(struct sockaddr_in));

    if (fd == SOCKET_FAILED_SOCKET) {
        printf("Failed to create socket!\n");
        return 1;
    }

    if (fd == SOCKET_FAILED_CONNECT) {
        printf("Failed to connect!\n");
        return 1;
    }

    uint8_t value[1];
    while (1) {
        int read_bytes = read(fd, value, 1);
        if (read_bytes > 0) {
            printf("%c", value[0]);
        } else {
            break;
        }
    }
    return 0;
}
