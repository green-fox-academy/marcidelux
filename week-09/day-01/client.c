#include<stdio.h>
#include<winsock2.h>

#pragma comment(lib,"ws2_32.lib") //Winsock Library

void wsadata_print(WSADATA* data);

int main(int argc , char *argv[])
{
    WSADATA wsa;
    SOCKET s;
    struct sockaddr_in server;
    char *message, server_reply[2000];
    int recv_size;

    printf("\n### Initialising Winsock...");
    if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
    {
        printf("Failed. Error Code : %d ###\n",WSAGetLastError());
        return 1;
    }

    printf("Initialised. ###\n");
    wsadata_print(&wsa);

    if((s = socket(AF_INET , SOCK_STREAM , 0 )) == INVALID_SOCKET)
    {
        printf("\n### Could not create socket : %d ###\n" , WSAGetLastError());
    }

    printf("\n### Socket created. ###\n");

    // origo: 46.107.16.51
    // google: 172.217.18.78
    server.sin_addr.S_un.S_addr = inet_addr("172.217.18.78");
    server.sin_family = AF_INET;
    server.sin_port = htons( 80 );
    //printf("Server socket address: %lu\n", server.sin_addr.s_addr);

    if (connect(s , (struct sockaddr *)&server , sizeof(server)) < 0) {
        puts("\n### connect error ###\n");
        return 1;
    }

    puts("\n### Connected ###\n");

    //Send some data
    message = "GET / HTTP/1.1\r\n\r\n";
    if( send(s , message , strlen(message) , 0) < 0)
    {
        puts("\n### Send failed ###\n");
        return 1;
    }
    puts("\n### Data has been sent ###\n");

    //Receive a reply from the server
    if((recv_size = recv(s , server_reply , 2000 , 0)) == SOCKET_ERROR)
    {
        puts("\n### recv failed ###\n");
    }

    puts("\n### Reply received ###\n");

    //Add a NULL terminating character to make it a proper string before printing
    server_reply[recv_size] = '\0';
    puts(server_reply);

    closesocket(s);
    printf("\n### Socket has been closed ###\n");
    WSACleanup();

    return 0;
}

void wsadata_print(WSADATA* data)
{
    printf("Max sockets:\t%d\n", data->iMaxSockets);
    printf("Max UpDgid:\t%d\n", data->iMaxUdpDg);
    printf("High Version:\t%d\n", data->wHighVersion);
    printf("Version:\t%d\n", data->wVersion);
    printf("Vendor info:\t%s\n", data->szDescription);
    printf("System status:\t%s\n", data->szSystemStatus);
    printf("\n");
}

char* get_host_ip(char *hostname)
{
    char ip[100];
    struct hostent *he;
    struct in_addr **addr_list;

    if ( (he = gethostbyname( hostname ) ) == NULL)
    {
        printf("gethostbyname failed : %d" , WSAGetLastError());
        return 1;
    }

    addr_list = (struct in_addr **) he->h_addr_list;

    for(int i = 0; addr_list[i] != NULL; i++)
    {
        strcpy(ip , inet_ntoa(*addr_list[i]) );
    }

    return &ip;
}