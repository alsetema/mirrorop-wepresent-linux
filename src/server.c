#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include "net.h"
#include "protocol.h"

int cmp(const uint8_t *data, const uint8_t *otherdata, int length) {
    for (int i = 0; i < length; i++) {
        if (data[i] != otherdata[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
/*    struct sockaddr_in stream_addr;
    stream_addr.sin_family = AF_INET;
    stream_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    stream_addr.sin_port = htons(515);*/

    struct sockaddr_in cmd_addr;
    cmd_addr.sin_family = AF_INET;
    cmd_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    cmd_addr.sin_port = htons(3268);

    int true = 1;

    /*int stream_socket = socket(AF_INET, SOCK_STREAM, 0);
    setsockopt(stream_socket, SOL_SOCKET, SO_REUSEADDR, &true, sizeof(int));*/

    int cmd_socket = socket(AF_INET, SOCK_STREAM, 0);
    setsockopt(cmd_socket, SOL_SOCKET, SO_REUSEADDR, &true, sizeof(int));

/*    int stream_bind = bind(stream_socket, (struct sockaddr *) &stream_addr, sizeof(struct sockaddr_in));

    if (stream_bind < 0) {
        printf("Could not bind stream socket\n");
        return 1;
    }*/

    int cmd_bind = bind(cmd_socket, (struct sockaddr *) &cmd_addr, sizeof(struct sockaddr_in));
    if (cmd_bind < 0) {
        //close(stream_socket);
        printf("Could not bind cmd socket.\n");
        return 2;
    }
    unsigned int socklen = sizeof(struct sockaddr_in);
    printf("%d\n", cmd_socket);

    listen(cmd_socket, 0);

    int cmd_accepted = accept(cmd_socket, (struct sockaddr *) &cmd_addr, &socklen);
    // int stream_accepted = accept(stream_socket, (struct sockaddr *) &stream_addr, &socklen);

    int cmd_file = open("cmd.bin", O_CREAT | O_WRONLY);

    uint8_t buffer[8192];

    while (1) {
        int read_from_cmd = read(cmd_accepted, buffer, 8192);
        if (read_from_cmd > 0) {
            printf("%d\n", CMD_CLIENT_ROCK_SIZE);
            write(cmd_file, buffer, read_from_cmd);
            if (read_from_cmd == CMD_CLIENT_ROCK_SIZE) {
                if (cmp(CMD_CLIENT_ROCK, buffer, CMD_CLIENT_ROCK_SIZE)) {
                    write(cmd_accepted, &CMD_SERVER_ROLL, CMD_SERVER_ROLL_SIZE);
                }
            }
            if (read_from_cmd == CMD_CLIENT_INFO_REQ_SIZE) {
                printf("Info req?\n");
                if (cmp(CMD_CLIENT_INFO_REQ, buffer, CMD_CLIENT_INFO_REQ_SIZE)) {
                    const uint8_t array[] = {0x77, 0x70, 0x70, 0x63, 0x6D, 0x64, 0x00, 0x00, 0x91, 0x41, 0x57, 0x50,
                                             0x50, 0x82, 0xF0, 0x22,
                                             0x24, 0x01, 0xBB, 0x7C, 0x79, 0x04, 0x11, 0x27, 0x0C, 0x42, 0x69, 0x62,
                                             0x6C, 0x6F, 0x2D, 0x53,
                                             0x74, 0x75, 0x64, 0x69, 0x6F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                             0x00, 0x00, 0x00, 0x00,
                                             0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                             0x00, 0x00, 0x00, 0x00,
                                             0x00, 0x61, 0x77, 0x69, 0x6E, 0x64, 0x00, 0x00, 0x30, 0x30, 0x30, 0x31,
                                             0x31, 0x31, 0x31, 0x30,
                                             0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0xEF, 0x79, 0x00, 0x00, 0x00,
                                             0x00, 0x00, 0x00, 0x00,
                                             0x00, 0x01, 0x2D, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x57,
                                             0x69, 0x50, 0x47, 0x32,
                                             0x4B, 0x53, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02,
                                             0x05, 0x01, 0x08, 0x0C,
                                             0x01, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
                    write(cmd_accepted, array, sizeof(array));
                }
            }
        }
        printf("Bruh, %d\n", read_from_cmd);
        if (read_from_cmd <= 0) {
            close(cmd_accepted);
            break;
        }
    }
    close(cmd_socket);
}