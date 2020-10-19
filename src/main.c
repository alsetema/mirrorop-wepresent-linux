#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <getopt.h>
#include <stdlib.h>
#include <threads.h>
#include "net.h"

#define MAJOR 0
#define MINOR 0
#define REV 1


int cmd_socket;
int video_socket;

const struct option long_options[] = {
        {"code", required_argument, 0, 'c'},
        {0, 0,                      0, 0}
};

void print_help(char *name){
    printf("OpMirror V%d.%d.%d help menu.\n", MAJOR, MINOR, REV);
    printf("Format: %s [options] <host>\n", name);
    printf("Available options:\n");
    printf("    -h            print this help menu and exit\n");
    printf("    -c [code]\n");
    printf("    --code [code] The authentication code to use\n");
}

int main(int argc, char *argv[]) {
    char *ip;
    char *code;
    uint16_t cmd_control_port = 3286;
    uint16_t video_port = 515;
    int option;
    while ((option = getopt_long(argc, argv, ":hc:", long_options, NULL)) != -1) {
        switch (option) {
            case 'c': {
                code = optarg;
                break;
            }
            case 'h': {
                print_help(argv[0]);
                return 0;
            }
            default: {
                print_help(argv[0]);
                return 1;
            }
        }
    }
    // "Skip over" all the arguments that getopt() has scanned
    argv = argv + optind;
    // Adjust the amount of leftover arguments appropriately
    argc = argc - optind;

    if (argc != 1) {
        printf("Missing required host argument.\n");
        return 1;
    }

    ip = argv[0];

    struct sockaddr_in cmd_addr;
    struct sockaddr_in video_addr;

    int sockaddr_result = get_in_addr(ip, cmd_control_port, &cmd_addr);

    if (sockaddr_result != 0) {
        printf("Invalid address\n");
        return 1;
    }

    cmd_socket = open_tcp_socket(cmd_addr, sizeof(struct sockaddr_in));

    if (cmd_socket == SOCKET_FAILED_CREATE) {
        printf("Failed to create socket!\n");
        return 1;
    }

    if (cmd_socket == SOCKET_FAILED_CONNECT) {
        printf("Failed to connect!\n");
        return 1;
    }

    int buffer_size = 1000;
    int *buffer = malloc(buffer_size);
    while(0 == 0) {
        int read_result = read(cmd_socket, buffer, buffer_size);
        if (read_result > 0) {

            printf("%*.s",read_result, buffer);
            write(cmd_socket, buffer, read_result);
        
        } else {
            break;
        }
        

    }
    
    return 0;


}
