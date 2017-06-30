#include "broadcast_listener.h"
#include "sender.h"
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <errno.h>
#include <process.h>
#include <winsock2.h>
#include <time.h>


void broadcast_server()
{
    SOCKET server_socket;
    struct sockaddr_in server_address, client_address;
    int recv_bytes;
    unsigned int clientLength;
    char message[4096];
    const char s[2] = " ";
    char *token;


    if((server_socket = socket(AF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET) {
        printf("Could not create socket : %d\n\n", WSAGetLastError());
    } else {
        printf("Socket created.\n\n");
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(12345);

    if( bind(server_socket,(struct sockaddr *)&server_address, sizeof(server_address)) == SOCKET_ERROR) {
        printf("Bind failed with error code : %d\n\n", WSAGetLastError());
    } else {
        puts("Bind done.\n");
    }
    while(1) {

        puts("Waiting for incoming data...\n");

        clientLength = sizeof(client_address);

        recv_bytes= recvfrom(server_socket, message, 4096, 0, (struct sockaddr*) &client_address, &clientLength);

        if(recv_bytes == SOCKET_ERROR) {
            puts("recv failed.\n");
        } else {
            printf("SERVER: read %d bytes from IP %s(%s)\n", recv_bytes, inet_ntoa(client_address.sin_addr), message);
        }

    char *token;
    token = strtok(message, s);

    if (strcmp("TOTORO", token) == 0) {
        token = strtok(NULL, s);
        send_message_to_discovery(inet_ntoa(client_address.sin_addr), atoi(token));
        printf("Message has been sent to ip: %s port: %s", inet_ntoa(client_address.sin_addr), token);
    }

    }

    closesocket(server_socket);
}
