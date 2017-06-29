#include "broadcast_listener.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <winsock2.h>

void broadcast_listener_thread()
{
    struct sockaddr_in addr;
    int socketfd,t=1;
    char *buf = "Napolion 5656";

    socketfd = socket(PF_INET,SOCK_DGRAM,0);
    memset(&addr, 0, sizeof(struct sockaddr_in));

    addr.sin_family = AF_INET;
    addr.sin_port = htons(BROADCAST_PORT);
    addr.sin_addr.s_addr = htonl(INADDR_BROADCAST);

    while(1) {

        if (setsockopt(socketfd, SOL_SOCKET, SO_BROADCAST ,&t, sizeof(t)))
             //printf("setsockopt");

        if(bind(socketfd,(struct sockaddr*) &addr,sizeof(addr)) < 0) {
            sendto(socketfd, buf, strlen(buf), 0, (struct sockaddr *)&addr, sizeof(addr));
        }
    }

}
