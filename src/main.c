#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include "net.h"


int socket1;
int socket2;
int socket3;

int main(int argc, char *argv[]) {
    const char ip[] = "127.0.0.1";
    uint16_t port = 5555;


    struct sockaddr_in addr1;
    struct sockaddr_in addr2;
    struct sockaddr_in addr3;

    int result1 = get_in_addr(ip, port, &addr1);

    if (result1 != 0){
        printf("Invalid address or port!\n");
        return 1;
    }

    int fd = open_tcp_socket(addr1, sizeof(struct sockaddr_in));

    if (fd == SOCKET_FAILED_CREATE) {
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
