#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>


int socket1;
int socket2;
int socket3;


//need to make sockets for port 3268,1234(maybe not since rst sent back),6542,515

struct sockaddr_in remote_address_port1;
remote_address.sin_family = AF_INET;
remote_address.sin_port = htons()
//fuck i cant remember shit, ask jona
int main(int argc, char *argv[]) {
    if(argc > 0 && argc <=1) {
        socket1 = socket(AF_INET, SOCK_STREAM, 0);

        int result_of_conversion = inet_pton(AF_INET, argv[0],
    }
}
