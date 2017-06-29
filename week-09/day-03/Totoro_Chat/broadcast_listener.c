#include "broadcast_listener.h"
#include "user.h"
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <errno.h>
#include <process.h>
#include <winsock2.h>
#include <time.h>


void broadcast_server(totoro_user *users, WSADATA *wsaData)
{
    SOCKET server_socket;
    struct sockaddr_in server_address, client_address;
    int recv_bytes;
    unsigned int clientLength = sizeof(client_address);
    char message[4096];
    const char s[2] = " ";
    char *token;

    int iResult = WSAStartup(MAKEWORD(2, 2), wsaData);
    if (iResult != NO_ERROR) {
        wprintf(L"WSAStartup failed with error: %d\n", iResult);
        return;
    }

    if((server_socket = socket(AF_INET , SOCK_DGRAM , 0)) == INVALID_SOCKET) {
        printf("Could not create socket : %d\n\n" , WSAGetLastError());
    } else {
        printf("Socket created.\n\n");
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(12345);

    if( bind(server_socket ,(struct sockaddr *)&server_address , sizeof(server_address)) == SOCKET_ERROR) {
        printf("Bind failed with error code : %d\n\n" , WSAGetLastError());
    } else {
        puts("Bind done.\n");
    }

    listen(server_socket , 50);
    puts("Waiting for incoming data...\n");

    recv_bytes= recvfrom(server_socket, message, 4096, 0, (struct sockaddr*) &client_address, &clientLength);

    if(recv_bytes == SOCKET_ERROR) {
        puts("recv failed.\n");
    } else {
        printf("SERVER: read %d bytes from IP %s(%s)\n", recv_bytes, inet_ntoa(client_address.sin_addr), message);
    }


    token = strtok(message, s);
    printf("name: %s\n", token);
    token = strtok(NULL, s);
    printf( "%s\n", token );

    /*
    int fing = *user_index;
        if(inet_ntoa(client_address.sin_addr) == user_array[fing - 1].ip_address && fing != 0 && fing != 1) {
            printf("hmmm");
        } else if(inet_ntoa(client_address.sin_addr) != user_array[fing].ip_address) {

            user_array[*user_index].discovery_port_number = atoi(token);
            user_array[*user_index].ip_address = inet_ntoa(client_address.sin_addr);
            (*user_index)++;
        }
    */

    closesocket(server_socket);
    WSACleanup();
}
